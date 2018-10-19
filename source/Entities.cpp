#include <>
namespace Alice {
Entities::Entities(boost::optional<Tokens> token, boost::optional<Value> value,
                   boost::optional<std::string> type) {
  this->token = token;
  this->value = value;
  this->type = type;
}

std::vector<Entity> Entities::EntitiesArr() const { return entitiesarr; }

boost::optional<Tokens> Entities::Token() const { return token; }

boost::optional<Value> Entities::Value() const { return value; }

boost::optional<std::string> Entities::Type() const { return type; }
}
