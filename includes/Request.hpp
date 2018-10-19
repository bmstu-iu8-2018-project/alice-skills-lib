#include <string>
#include <string>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>
#include <boost/optional.hpp>
#include "Meta.hpp"
#include "Session.hpp"
namespace Alice {
enum RequestType { SimpleUtterance, ButtonPressed };
class Request {
  Meta meta;
  Session session;
  std::string command;
  std::string originalutterance;
  std::string payload;
  std::string version;
  RequestType type;
  boost::optional<bool> isdangerouscontext = boost::none;
  Tokens strtoken;
  std::vector<boost::optional<Entity>> entities;

public:
  Request(const std::string &); // конструктор, который парсит Json от
                                // пользователя и инициализирует поля класса

  const Meta &Meta() const;
  const Session &Session() const;
  const std::srting &Version() const;
  std::string Command() const;
  std::string OriginalUtterance() const;
  RequestType Type() const;
  boost::optional<bool> IsDangerousContext() const;
  std::string Payload() const;
  Tokens StrToken() const;
  std::vector<boost::optional<Entity>> Entities();
};
} // namespace