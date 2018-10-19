namespace Alice {
class Value {
  boost::optional<std::string> firstname = boost::none;
  boost::optional<std::string> patronymicname = boost::none;
  boost::optional<std::string> lastname = boost::none;
  boost::optional<std::string> country = boost::none;
  boost::optional<std::string> city = boost::none;
  boost::optional<std::string> street = boost::none;
  boost::optional<std::string> housenumber = boost::none;
  boost::optional<std::string> airport = boost::none;
  boost::optional<int> year = boost::none;
  boost::optional<int> month = boost::none;
  boost::optional<int> day = boost::none;
  boost::optional<int> hour = boost::none;
  boost::optional<int> minute = boost::none;
  boost::optional<bool> yearisrelative = boost::none;
  boost::optional<bool> mothisrelative = boost::none;
  boost::optional<bool> dayisrelative = boost::none;
  boost::optional<bool> hourisrelative = boost::none;
  boost::optional<bool> minutisrelative = boost::none;
  boost::optional<float> valueval = boost::none;

public:
  Value(boost::optional<std::string> firstname,
        boost::optional<std::string> patronymicname,
        boost::optional<std::string> lastname,
        boost::optional<std::string> country, boost::optional<std::string> city,
        boost::optional<std::string> street,
        boost::optional<std::string> housenumber,
        boost::optional<std::string> airport, boost::optional<unsigned> year,
        boost::optional<unsigned> month, boost::optional<int> day,
        boost::optional<unsigned> hour, boost::optional<unsigned> minute,
        boost::optional<bool> yearisrelative,
        boost::optional<bool> mothisrelative,
        boost::optional<bool> dayisrelative,
        boost::optional<bool> hourisrelative,
        boost::optional<bool> minutisrelative, boost::optional<float> valueval);

  boost::optional<std::string> FirstName() const;
  boost::optional<std::string> PatronymicName() const;
  boost::optional<std::string> LastName() const;
  boost::optional<std::string> Country() const;
  boost::optional<std::string> City() const;
  boost::optional<std::string> Street() const;
  boost::optional<std::string> HouseNumber() const;
  boost::optional<std::string> Airport() const;
  boost::optional<unsigned> Year() const;
  boost::optional<unsigned> Month() const;
  boost::optional<int> Day() const;
  boost::optional<unsigned> Hour() const;
  boost::optional<unsigned> Minute() const;
  boost::optional<bool> YearIsRelative() const;
  boost::optional<bool> MonthIsRelative() const;
  boost::optional<bool> DayIsRelative() const;
  boost::optional<bool> HourIsRelative() const;
  boost::optional<bool> MinuteIsRelative() const;
  boost::optional<float> ValueVal() const;
}
}