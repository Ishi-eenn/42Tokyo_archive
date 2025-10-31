#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq) :compareCount(0) {
  _vec = vec;
  _deq = deq;
}

PmergeMe::PmergeMe(const PmergeMe& other) :_vec(other._vec), _deq(other._deq), compareCount(other.compareCount) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    _vec = other._vec;
    _deq = other._deq;
    compareCount = other.compareCount;
  }

  return *this;
}

PmergeMe::vecContainer& PmergeMe::getContainerVec() {
  return _vec;
}

const PmergeMe::vecContainer& PmergeMe::getContainerVec() const {
  return _vec;
}

PmergeMe::deqContainer& PmergeMe::getContainerDeque() {
  return _deq;
}

const PmergeMe::deqContainer& PmergeMe::getContainerDeque() const {
  return _deq;
}

void PmergeMe::integrateToMainChain(vecContainer& data,
    vecContainer::size_type groupSize,
    vecContainer::size_type chunkSize,
    bool hasUnpairedGroup)
{
    vecMainChain tmp = makeTempMainChain(data, groupSize);
    integrateToMainChainImpl(data, groupSize, chunkSize, hasUnpairedGroup, tmp);
    data = buildContainerFromMainchain(data, groupSize / 2, tmp);
}

void PmergeMe::integrateToMainChain(deqContainer& data,
    deqContainer::size_type groupSize,
    deqContainer::size_type chunkSize,
    bool hasUnpairedGroup)
{
    deqMainChain tmp = makeTempMainChain(data, groupSize);
    integrateToMainChainImpl(data, groupSize, chunkSize, hasUnpairedGroup, tmp);
    data = buildContainerFromMainchain(data, groupSize / 2, tmp);
}

PmergeMe::vecMainChain PmergeMe::makeTempMainChain(const vecContainer& data, const vecContainer::size_type groupSize) {

  vecMainChain tmpMainChain;

  tmpMainChain.push_back(std::make_pair(data[(groupSize / 2) - 1], data.begin() + (groupSize / 2) - 1));
  for (vecContainer::size_type i = 1; (i * groupSize - 1) < data.size(); ++i)
    tmpMainChain.push_back(std::make_pair(data[(groupSize * i) - 1], data.begin() + (groupSize * i) - 1));
  return tmpMainChain;
}

PmergeMe::deqMainChain PmergeMe::makeTempMainChain(const deqContainer& data, const deqContainer::size_type groupSize) {

  deqMainChain tmpMainChain;

  tmpMainChain.push_back(std::make_pair(data[(groupSize / 2) - 1], data.begin() + (groupSize / 2) - 1));
  for (deqContainer::size_type i = 1; (i * groupSize - 1) < data.size(); ++i)
    tmpMainChain.push_back(std::make_pair(data[(groupSize * i) - 1], data.begin() + (groupSize * i) - 1));
  return tmpMainChain;
}

PmergeMe::vecContainer PmergeMe::buildContainerFromMainchain(const vecContainer& data,
  const vecContainer::size_type& groupSize, const vecMainChain& mainChain)
{
  vecContainer	reconstructData;
  unsigned int remainData = data.size() % groupSize;

  reconstructData.reserve(data.size());
  for (vecContainer::size_type i = 0; i < mainChain.size(); ++i)
    reconstructData.insert(reconstructData.end(), mainChain[i].second - groupSize + 1, mainChain[i].second + 1);
  if (remainData)
    reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
  return reconstructData;
}

PmergeMe::deqContainer PmergeMe::buildContainerFromMainchain(const deqContainer& data,
  const deqContainer::size_type& groupSize, const deqMainChain& mainChain)
{
  deqContainer	reconstructData;
  unsigned int remainData = data.size() % groupSize;

  for (deqContainer::size_type i = 0; i < mainChain.size(); ++i)
    reconstructData.insert(reconstructData.end(), mainChain[i].second - groupSize + 1, mainChain[i].second + 1);
  if (remainData)
    reconstructData.insert(reconstructData.end(), data.end() - remainData, data.end());
  return reconstructData;
}
