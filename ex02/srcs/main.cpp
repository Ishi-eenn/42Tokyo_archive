#include "PmergeMe.hpp"
#include <sstream>

namespace Array {

  // コンテナの要素を区切って文字列化
  template <typename T>
  std::string joinElements(const T& data, const std::string& sep = " ") {
    std::ostringstream oss;
    for (typename T::size_type i = 0; i < data.size(); ++i) {
      if (i > 0) oss << sep;
      oss << data[i];
    }
    return oss.str();
  }

  // ラベル付きで出力
  template <typename T>
  void show(const std::string& label, const T& data, std::ostream& os = std::cout) {
    os << label << ": " << joinElements(data) << std::endl;
  }

  template <typename T>
  void showBefore(const T& data) {
    show("Before", data);
  }

  template <typename T>
  void showAfter(const T& data) {
    show("After", data);
  }

  // 文字列を整数に変換（エラー時は例外を投げる）
  inline int toInt(const char* str) {
    std::istringstream iss(str);
    int val;

    if (!(iss >> val) || !iss.eof())
      throw std::invalid_argument("Invalid numeric input: " + std::string(str));
    return val;
  }

  template <typename T>
  T makeContainerFromArgs(int argc, char** argv) {
    T c;

    for (int i = 1; i < argc; ++i) {
      int val = toInt(argv[i]);

      c.push_back(val);
    }
    return c;
  }


}

namespace timer {

  // 時間計測のクラス
  class Stopwatch {

    private:
      std::clock_t start_;

    public:
      Stopwatch() : start_(0) {}

      void start() {
        start_ = std::clock();
      }

      double stop() const {
        return static_cast<double>(std::clock() - start_) / CLOCKS_PER_SEC;
      }
  };

  // 出力関数
  inline void showResult(const std::string& containerName, std::size_t size, double duration) {
    std::cout << "Time to process a range of "
              << size << " elements with " << containerName
              << " : " << duration * 1000000 << " us" << std::endl;
  }

  inline void showVector(std::size_t size, double duration) {
    showResult("std::vector", size, duration);
  }

  inline void showDeque(std::size_t size, double duration) {
    showResult("std::deque", size, duration);
  }

}

namespace validate {

  namespace internal {

    // 数字以外が入ってるか確認
    inline bool isAllDigits(const char* s) {
      if (!s || *s == '\0') return false;
      const unsigned char* p = reinterpret_cast<const unsigned char*>(s);
      for (; *p; ++p) {
        if (!std::isdigit(*p)) return false;
      }
      return true;
    }

    // オーバーフローチェック
    inline int toIntChecked(const char* s) {
      int val = 0;
      for (const char* p = s; *p; ++p) {
        int d = *p - '0';
        if (val > (INT_MAX - d) / 10) {
          throw std::invalid_argument(std::string("Error: argument '") + s + "' exceeds INT_MAX.");
        }
        val = val * 10 + d;
      }
      return val;
    }

    // 先頭の'0'をスキップ
    inline const char* skipLeadingZeros(const char* s) {
      const char* p = s;
      while (*p == '0') ++p;
      return p;
    }

    // 桁数を数える
    inline int digitCountFrom(const char* s) {
      const char* p = s;
      while (*p) ++p;
      return static_cast<int>(p - s);
    }

    // 数値として等しいか？（"01" と "1" を同値とみなす）
    inline bool equalsNumericValue(const char* a, const char* b) {
      const char* pa = skipLeadingZeros(a);
      const char* pb = skipLeadingZeros(b);

      // どちらも全て'0'の場合 → "0"同士とみなす
      const char* na = (*pa ? pa : "0");
      const char* nb = (*pb ? pb : "0");

      const int la = (*pa ? digitCountFrom(pa) : 1);
      const int lb = (*pb ? digitCountFrom(pb) : 1);

      if (la != lb) return false;
      for (int i = 0; i < la; ++i) {
        if (na[i] != nb[i]) return false;
      }
      return true;
    }

  }

  namespace check {

    // 数字構文チェック
    inline void syntax(const char* arg) {
      if (!internal::isAllDigits(arg))
        throw std::invalid_argument(std::string("Error: argument '") + arg + "' is not a valid non-negative integer.");
    }

    // 範囲チェック（0〜INT_MAX）
    inline void range(const char* arg) {
      (void)internal::toIntChecked(arg);
    }

    // 重複チェック（数値的に同値ならエラー）
    inline void duplicates(int ac, char** av) {
      for (int i = 1; i < ac; ++i) {
        for (int j = i + 1; j < ac; ++j) {
          if (internal::equalsNumericValue(av[i], av[j])) {
            throw std::invalid_argument(std::string("Error: duplicate argument '") + av[i] + "'.");
          }
        }
      }
    }

    // まとめて検証
    inline void arguments(int argc, char** argv) {
      if (argc < 2)
        throw std::invalid_argument("Error: no arguments provided.");

      // 各要素を個別チェック
      for (int i = 1; i < argc; ++i) {
        syntax(argv[i]);
        range(argv[i]);
      }

      // 重複チェック
      duplicates(argc, argv);
    }

  }

}

int main(int argc, char** argv) {

  try {
    validate::check::arguments(argc, argv);

    std::vector<int> vec = Array::makeContainerFromArgs<std::vector<int> >(argc, argv);
    std::deque<int>  deq = Array::makeContainerFromArgs<std::deque<int> >(argc, argv);

    PmergeMe data(vec, deq);
    Array::showBefore(data.getContainerVec());

    timer::Stopwatch watch;

    // ---- vector ----
    watch.start();
    data.mergeInsertionSort(data.getContainerVec(), 1, data.getContainerVec().size(), false);
    double vecDuration = watch.stop();
    Array::showAfter(data.getContainerVec());
    timer::showVector(data.getContainerVec().size(), vecDuration);

    // ---- deque ----
    watch.start();
    data.mergeInsertionSort(data.getContainerDeque(), 1, data.getContainerDeque().size(), false);
    double deqDuration = watch.stop();
    timer::showDeque(data.getContainerDeque().size(), deqDuration);

  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
