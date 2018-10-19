namespace Alice {
class Meta {
  std::string locale;
  std::string timezone;
  td::string clientid;

public:
  Meta(std::string locale, std::string timezone,
       std::string clientid); //конструктор класса Meta
  std::string Locale() const;
  std::string Timezone() const;
  std::string ClientId() const;
};
} // namespace