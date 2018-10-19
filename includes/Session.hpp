namespace Alice {
class Session {
  boost::optional<bool> isnew;
  std::string sessionid;
  boost::optional<std::string> skillid;
  std::string userid;

public:
  Session(boost::optional<bool> isnew, size_t messageId, std::string sessionId,
          boost::optional<std::string> skillid,
          std::string userid); // Конструктор класса Session для Requets
  boost::optional<bool> IsNew() const;
  size_t MessageId() const;
  std::string SessionId() const;
  boost::optional<std::string> SkillId() const;
  std::string UserId() const;
};
} // namespace