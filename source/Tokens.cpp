#include <Tokens.hpp>
namespace Alice {
Tokens::Tokens(std::vector<boost::optional<std::string>> wordsarray,
               boost::optional<unsigned> start, boost::optional<unsigned> end) {
  this->wordsarray = wordsarray;
  this->start = start;
  this->end = end;
}

std::vector<boost::optional<std::string>> Tokens::WordsArray() const {
  return wordsarray;
}

boost::optional<unsigned> Tokens::Start() const { return start; }

boost::optional<unsigned> Tokens::End() const { return end; }
}