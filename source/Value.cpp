#include <Value.hpp>
namespace Alice {
Value::Value(
    boost::optional<std::string> firstname,
    boost::optional<std::string> patronymicname,
    boost::optional<std::string> lastname, boost::optional<std::string> country,
    boost::optional<std::string> city, boost::optional<std::string> street,
    boost::optional<std::string> housenumber,
    boost::optional<std::string> airport, boost::optional<unsigned> year,
    boost::optional<unsigned> month, boost::optional<int> day,
    boost::optional<unsigned> hour, boost::optional<unsigned> minute,
    boost::optional<bool> yearisrelative, boost::optional<bool> monthisrelative,
    boost::optional<bool> dayisrelative, boost::optional<bool> hourisrelative,
    boost::optional<bool> minuteisrelative, boost::optional<float> valueval) {
  this->firstname = firstname;
  this->patronymicname = patronymicname;
  this->lastname = lastname;
  this->city = city;
  this->housenumber = housenumber;
  this->airport = airport;
  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->minute = minute;
  this->yearisrelative = dayisrelative;
  this->monthisrelative = dayisrelative;
  this->dayisrelative = dayisrelative;
  this->hourisrelative = dayisrelative;
  this->minuteisrelative = dayisrelative;
  this->valueval = valueval;
}
boost::optional<std::string> Value::FirstName() const { return firstname; }

boost::optional<std::string> Value::PatronymicName() const {
  return patronymicname;
}

boost::optional<std::string> Value::LastName() const { return lastname; }

boost::optional<std::string> Value::Country() const { return country; }

boost::optional<std::string> Value::City() const { return city; }

boost::optional<std::string> Value::Street() const { return street; }

boost::optional<std::string> Value::HouseNumber() const { return housenumber; }

boost::optional<std::string> Value::Airport() const { return airport; }

boost::optional<unsigned> Value::Year() const { return year; }

boost::optional<unsigned> Value::Month() const { return month; }

boost::optional<int> Value::Day() const { return day; }

boost::optional<unsigned> Value::Hour() const { return hour; }

boost::optional<unsigned> Value::Minute() const { return minute; }

boost::optional<bool> Value::YearIsRelative() const { return dayisrelative; }

boost::optional<bool> Value::MonthIsRelative() const { return dayisrelative; }

boost::optional<bool> Value::DayIsRelative() const { return dayisrelative; }

boost::optional<bool> Value::HourIsRelative() const { return dayisrelative; }

boost::optional<bool> Value::MinuteIsRelative() const { return dayisrelative; }

boost::optional<float> Value::ValueVal() const { return valueval; }
}