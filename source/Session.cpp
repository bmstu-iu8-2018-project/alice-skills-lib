#include <Session.hpp>
namespace Alice {
Session::Session(boost::optional<bool> isnew, size_t messageid,
                 std::string sessionid, boost::optional<std::string> skillid,
                 std::string userid) {
  this->isnew = isnew;
  this->messageid = messageid;
  this->sessionid = sessionid;
  this->skillid = skillid;
  this->userid = userid;
}

boost::optional<bool> Session::IsNew() const { return isnew; }

size_t Session::MessageId() const { return messageid; }

std::string Session::SessionId() const { return sessionid; }

boost::optional<std::string> SkillId() const { return skillid; }

std::string UserId() const { return userid; }
}