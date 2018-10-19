namespace Alice {
class Tokens {
  std::vector<boost::optional<std::string>> wordsarray = boost::none;
  boost::optional<unsigned> start = boost::none;
  boost::optional<unsigned> end = boost::none;

public:
  Tokens(std::vector<boost::optional<std::string>> wordsarray,
         boost::optional<unsigned> start, boost::optional<unsigned> end);
  std::vector<boost::optional<std::string>> WordsArray() const;
  boost::optional<unsigned> Start() const;
  boost::optional<unsigned> End() const;
}
}