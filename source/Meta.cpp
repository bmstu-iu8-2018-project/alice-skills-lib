#include <Meta.hpp>
namespace Alice {
Meta::Meta(std::string locale, std::string timezone, std::string clientid) {
  this->locale = locale;
  this->timezone = timezone;
  this->clientid = clientid;
}

std::string Meta::Locale() const { return locale; }
std::string Meta::TimeZone() const { return timezone; }
std::string Meta::ClientId() const { return ClientId; }
} // namespace