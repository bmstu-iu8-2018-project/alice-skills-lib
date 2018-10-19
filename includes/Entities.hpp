namespace Alice {
class Entity {
  boost::optional<Tokens> token;
  boost::optional<Value> value;
  boost::optional<std::string> type;

public:
  Entity(boost::optional<Tokens> token, boost::optional<Value> value,
         boost::optional<std::string> type);
  boost::optional<Tokens> Token() const;
  boost::optional<Value> Value() const;
  boost::optional<std::string> Type() const;
}