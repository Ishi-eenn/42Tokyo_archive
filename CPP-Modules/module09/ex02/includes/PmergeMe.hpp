#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <algorithm>

class PmergeMe {
  public:
    typedef std::vector<int> vecContainer;
    typedef std::pair<int, vecContainer::const_iterator> pairMainChain;
    typedef std::vector<pairMainChain> vecMainChain;

    typedef std::deque<int> deqContainer;
    typedef std::pair<int, deqContainer::const_iterator> pairMainChainDeq;
    typedef std::deque<pairMainChainDeq> deqMainChain;

    PmergeMe(std::vector<int>, std::deque<int>);
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& rhs);

    vecContainer& getContainerVec();
    const vecContainer& getContainerVec() const;
    deqContainer& getContainerDeque();
    const deqContainer& getContainerDeque() const;

    // compareChunkAndSwap は「[i, i+groupSize) と [i+groupSize, i+2*groupSize)」を
    // 末尾(=そのチャンクの最大)で比較して、必要なら右チャンクを左の前に回転（std::rotate）する。
    // integrateToMainChain は、そのスケールで分割されたチャンク群を一本に“挿入統合”する。
    template <typename C>
    void mergeInsertionSort(
        C& data,
        typename C::size_type groupSize,   // 1チャンクの要素数（再帰ごとに倍化）
        typename C::size_type numPairs,    // この段で扱う「チャンクのペア数」
        int hasUnpairedGroup                   // 余り（ペアにできないチャンク）があるか
    ){
      // ベース条件：この段で比較するペアがない
      if (numPairs < 1)
        return;

      // 1) 同スケールの隣接チャンクを「最大要素」で比較し、逆なら入れ替え
      compareChunkAndSwap(data, groupSize);

      // 2) スケールを倍にして、ペア数は半分にして再帰
      mergeInsertionSort(data, groupSize * 2, numPairs / 2, (numPairs % 2) != 0);

      // 3) このスケールで一本の“主列”に統合（挿入）
      if (groupSize > 1) {
        // hasUnpairedGroup を 0/1 に正規化して渡す
        integrateToMainChain(data, groupSize, numPairs, hasUnpairedGroup);
      }

      #ifdef DEBUG
        if (groupSize == 1) {
          std::cout << "compare count: " << compareCount << std::endl;
          compareCount = 0;
        }
      #endif
    }

      template <typename TContainer>
      void printContainer(const TContainer& data) {
        for (typename TContainer::size_type i = 0; i < data.size(); ++i)
          std::cout << data[i] << " ";
        std::cout << std::endl;
      };

  private:
    PmergeMe();

    vecContainer _vec;
    deqContainer _deq;
    size_t compareCount;

  private:
    vecMainChain makeTempMainChain(const vecContainer& data, const vecContainer::size_type groupSize);
    deqMainChain makeTempMainChain(const deqContainer& data, const deqContainer::size_type groupSize);
    void integrateToMainChain(vecContainer& data,
      vecContainer::size_type groupSize,
      vecContainer::size_type chunkSize,
      bool hasUnpairedGroup);
    void integrateToMainChain(deqContainer& data,
      deqContainer::size_type groupSize,
      deqContainer::size_type chunkSize,
      bool hasUnpairedGroup);
    vecContainer buildContainerFromMainchain(const vecContainer& data,
      const vecContainer::size_type& groupSize, const vecMainChain& mainChain);
    deqContainer buildContainerFromMainchain(const deqContainer& data,
      const deqContainer::size_type& groupSize, const deqMainChain& mainChain);

    template <typename C, typename MainChain>
    void integrateToMainChainImpl(
        C& data,
        typename C::size_type groupSize,
        typename C::size_type chunkSize,
        bool hasUnpairedGroup,
        MainChain& tmpMainChain
    ) {
        typename C::size_type iEnd = getNextIntegratePos<C>(1); // 1
        // tmpMainChain は呼び出し側で makeTempMainChain(data, groupSize) して渡す

        for (typename C::size_type iIntegrateGroup = 2;
            iEnd < chunkSize + (hasUnpairedGroup ? 1 : 0);
            ++iIntegrateGroup)
        {
            typename C::size_type iTarget = getNextIntegratePos<C>(iIntegrateGroup) - 1;

            while (iEnd <= iTarget) {
                typename C::size_type targetIndex = (groupSize * iTarget) + (groupSize / 2) - 1;

                if (iTarget < (chunkSize + (hasUnpairedGroup ? 1 : 0))) {
                    typename C::value_type targetVal = data[targetIndex];

                    typename MainChain::iterator insertPos =
                        recursiveSearchInsertPos<MainChain>(
                            tmpMainChain.begin(),
                            (targetIndex + 1 < groupSize * chunkSize
                              ? std::find(
                                    tmpMainChain.begin(),
                                    tmpMainChain.end(),
                                    std::make_pair(
                                      data[targetIndex + (groupSize / 2)],
                                      static_cast<typename C::const_iterator>(data.begin() + targetIndex + (groupSize / 2)))
                                )
                              : tmpMainChain.end()),
                            std::make_pair(targetVal, static_cast<typename C::const_iterator>(data.begin() + targetIndex))
                        );

                    tmpMainChain.insert(insertPos, std::make_pair(targetVal, static_cast<typename C::const_iterator>(data.begin() + targetIndex)));
                }
                --iTarget;
            }
            iEnd = getNextIntegratePos<C>(iIntegrateGroup);
        }
    }

    /**
     * @brief 隣接する2つのチャンクを比較し、順序が逆なら右チャンクを左チャンクの前に移動させる
     *
     * data: [chunkLeft][chunkRight]
     *  └── groupSize要素ごとに区切り、左チャンクの最大要素と右チャンクの最大要素を比較。
     *      左 > 右 の場合は、[chunkRight][chunkLeft] の順になるように並び替える。
     *
     * 例:
     *   data = [1,4, 2,3, 5,8, 6,7], groupSize = 2
     *   → 比較 (4 vs 3): 右を前へ移動 → [2,3, 1,4, 5,8, 6,7]
     *   → 比較 (8 vs 7): 右を前へ移動 → [2,3, 1,4, 6,7, 5,8]
     */
    template <typename C>
    void compareChunkAndSwap(C& data, typename C::size_type groupSize) {
      for (typename C::size_type i = 0; i + (groupSize * 2) <= data.size(); i += (groupSize * 2)) {
        // 左チャンクの最大要素と右チャンクの最大要素を比較
        if (!isLeftChunkSmaller(data, i + (groupSize - 1), i + (groupSize * 2) - 1)) {
          // [first, middle) → 左チャンク
          // [middle, last)  → 右チャンク
          typename C::iterator first  = data.begin() + i;
          typename C::iterator middle = data.begin() + i + groupSize;
          typename C::iterator last   = middle + groupSize;

          // rotateにより [first, middle) と [middle, last) の順序を入れ替える
          // 結果: 右チャンクが左チャンクの前に移動（各チャンク内部の順序は保持）
          std::rotate(first, middle, last);
        }
      }
    }

    /**
     * @brief 左右チャンクの末尾（最大要素）を比較し、左チャンクが右チャンク以下かを判定する
     *
     * チャンク内は昇順である前提で、それぞれの末尾要素（最大値）を比較。
     * 左の方が小さい（順序OK）場合は true を返す。
     *
     * @param container 比較対象のコンテナ
     * @param leftEnd   左チャンクの末尾インデックス
     * @param rightEnd  右チャンクの末尾インデックス
     * @return true  左チャンクの最大値 ≤ 右チャンクの最大値（順序OK）
     * @return false 左チャンクの最大値 > 右チャンクの最大値（要スワップ）
     */
    template <typename C>
    bool isLeftChunkSmaller(C& container, typename C::size_type leftEnd, typename C::size_type rightEnd) {
      # ifdef VS
        std::cout << container[leftEnd] << " - " << container[rightEnd] << std::endl;
      # endif

      ++compareCount;

      return container[leftEnd] <= container[rightEnd];
    }

    // ヤコブスタール数から次の統合位置を取得
    template <typename TContainer>
    typename TContainer::size_type getNextIntegratePos(const typename TContainer::size_type number) {
      return ((std::pow(2, number + 1) + std::pow(-1, number)) / 3);
    }

    template <typename TMainChain>
    typename TMainChain::iterator recursiveSearchInsertPos(typename TMainChain::iterator begin,
    typename TMainChain::iterator end, const typename TMainChain::value_type& targetVal) {
      if (begin == end)
        return (begin);
      else if ((end - begin) == 1) {
        ++compareCount;

        # ifdef VS
          std::cout << (*begin).first << " - " << targetVal.first << std::endl;
        # endif
        if (targetVal.first < (*begin).first)
          return (begin);
        else
          return (begin + 1);
      } else {
        ++compareCount;
        typename TMainChain::iterator middle = begin + ((end - begin) / 2);
        # ifdef VS
          std::cout << (*middle).first << " - " << targetVal.first << std::endl;
        # endif
        if (targetVal.first < (*middle).first)
          return recursiveSearchInsertPos<TMainChain>(begin, middle, targetVal);
        else
          return recursiveSearchInsertPos<TMainChain>(middle + 1, end, targetVal);
      }
    }
  };

# endif
