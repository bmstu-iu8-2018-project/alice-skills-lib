#include <Request.hpp>
namespace Alice {
Request::Request(const std::string &RequestStr) {
  auto RequestJson = json::parse(RequestStr);
  auto MetaJson = RequestJson["meta"];
  Meta metahelp(MetaJson["locale"], MetaJson["timezone"],
                MetaJson["client_id"]);
  meta = metahelp;
  auto ReqJson = RequestJson["request"];
  command = ReqJson["command"];
  originalutterance = ReqJson["original_utterance"];
  if (ReqJson.count("markup") != 0)
    isdangerouscontext = true;
  payload = ReqJson["payload"];
  std::string type_str = ReqJson["type"];
  if (type_str == "SimpleUtterance")
    type = SimpleUtterance;
  else
    type = ButtonPressed;
  auto SessionJson = RequestJson["session"];
  Session sessionhelp(SessionJson["new"], SessionJson["message_id"],
                      SessionJson["session_id"], SessionJson["skill_id"],
                      SessionJson["user_id"]);
  session = sessionhelp;
  version = RequestJson.at["version"];
  auto NluJson = RequestJson["nlu"];
  std::vector < boost::optional<std::string> wordsarray = boost::none;
  auto jsonwordsarray = NluJson["tokens"];
  unsigned i = 0;
  for (json::iterator it = jsonwordsarray.begin(); it != jsonwordsarray.end();
       ++it) {
    wordsarray[i] = *it;
    ++i;
  }
  Tokens tokenstrhelp(wordsarray, boost::none, boost::none);
  strtoken = tokenstrhelp;
  auto EntitiesJson = NluJson["entities"];
  if (EntitiesJson[0].count() != 0) { // работает ли для массива эта функция?
    auto Entity1Json = EntitiesJson[0];
    auto Token1Json = Entity1Json["tokens"];
    Tokens Token1(boost::none, Token1Json["start"], Token1Json["end"]);
    if (Entity1Json["type"] == "YANDEX.GEO")) {
        if (Entity1Json["country"].count() != 0)
          boost::optional < std : string > country = Entity1Json["country"];
        if (Entity1Json["city"].count() != 0)
          boost::optional < std : string > city = Entity1Json["city"];
        if (Entity1Json["street"].count() != 0)
          boost::optional < std : string > street = Entity1Json["street"];
        if (Entity1Json["house_numer"].count() != 0)
          boost::optional<unsigned> house_number = Entity1Json["house_number"];
        if (Entity1Json["airport"].count() != 0)
          boost::optional < std : string > airport = Entity1Json["airport"];
        Value value1(boost::none, boost::none, boost::none, country, city,
                     street, house_number, airport, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none);
        Entity entity1(Token1, value1, Entity1Json["type"]);
        entities[0] = entity1;
      }
    if (Entity1Json["type"] == "YANDEX.FIO") {
      if (Entity1Json["first_name"].count() != 0)
        boost::optional < std : string > first_name = Entity1Json["first_name"];
      if (Entity1Json["patronymic_name"].count() != 0)
        boost::optional < std : string > patronymic_name =
            Entity1Json["patronymic_name"];
      if (Entity1Json["last_name"].count() != 0)
        boost::optional < std : string > last_name = Entity1Json["last_name"];
      Value value1(first_name, patronymic_name, last_name, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none);
      Entity entity1(Token1, value1, Entity1Json["type"]);
      entities[0] = entity1;
    }
    if (Entity1Json["type"] == "YANDEX.DATETIME") {
      if (Entity1Json["year"].count() != 0)
        boost::optional<int> year = Entity1Json["year"];
      if (Entity1Json["month"].count() != 0)
        boost::optional<int> month = Entity1Json["month"];
      if (Entity1Json["day"].count() != 0)
        boost::optional<int> day = Entity1Json["day"];
      if (Entity1Json["hour"].count() != 0)
        boost::optional<int> hour = Entity1Json["hour"];
      if (Entity1Json["minute"].count() != 0)
        boost::optional<int> minute = Entity1Json["minute"];
      if (Entity1Json["year_is_relative"].count() != 0)
        boost::optional<bool> yearisrelative = Entity1Json["year_is_relative"];
      if (Entity1Json["month_is_relative"].count() != 0)
        boost::optional<bool> monthisrelative =
            Entity1Json["month_is_relative"];
      if (Entity1Json["day_is_relative"].count() != 0)
        boost::optional<bool> dayisrelative = Entity1Json["day_is_relative"];
      if (Entity1Json["hour_is_relative"].count() != 0)
        boost::optional<bool> year = Entity1Json["hour_is_relative"];
      if (Entity1Json["minute_is_relative"].count() != 0)
        boost::optional<bool> minuteisrelative =
            Entity1Json["minute_is_relative"];
      Value value1(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none, year,
                   month, day, hour, minute, yearisrelative, monthisrelative,
                   dayisrelative, hourisrelative, minuteisrelative,
                   boost::none);
      Entity entity1(Token1, value1, Entity1Json["type"]);
      entities[0] = entity1;
    }
    if (Entity1Json["type"] == "YANDEX.NUMBER") {
      if (Entity1Json["value"].count() != 0)
        boost::optional<float> value = Entity1Json["value"];
      Value value1(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, value);
      Entity entity1(Token1, value1, Entity1Json["type"]);
      entities[0] = entity1;
    }
  }
  if (EntitiesJson[1].count() != 0) { // работает ли для массива эта функция?
    auto Entity2Json = EntitiesJson[1];
    auto Token2Json = Entity2Json["tokens"];
    Tokens Token2(boost::none, Token2Json["start"], Token2Json["end"]);
    if (Entity2Json["type"] == "YANDEX.GEO")) {
        if (Entity2Json["country"].count() != 0)
          boost::optional < std : string > country = Entity2Json["country"];
        if (Entity2Json["city"].count() != 0)
          boost::optional < std : string > city = Entity2Json["city"];
        if (Entity2Json["street"].count() != 0)
          boost::optional < std : string > street = Entity2Json["street"];
        if (Entity2Json["house_numer"].count() != 0)
          boost::optional<unsigned> house_number = Entity2Json["house_number"];
        if (Entity2Json["airport"].count() != 0)
          boost::optional < std : string > airport = Entity2Json["airport"];
        Value value2(boost::none, boost::none, boost::none, country, city,
                     street, house_number, airport, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none);
        Entity entity2(Token2, value2, Entity2Json["type"]);
        entities[1] = entity2;
      }
    if (Entity2Json["type"] == "YANDEX.FIO") {
      if (Entity2Json["first_name"].count() != 0)
        boost::optional < std : string > first_name = Entity2Json["first_name"];
      if (Entity2Json["patronymic_name"].count() != 0)
        boost::optional < std : string > patronymic_name =
            Entity2Json["patronymic_name"];
      if (Entity2Json["last_name"].count() != 0)
        boost::optional < std : string > last_name = Entity2Json["last_name"];
      Value value2(first_name, patronymic_name, last_name, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none);
      Entity entity2(Token2, value2, Entity2Json["type"]);
      entities[1] = entity2;
    }
    if (Entity2Json["type"] == "YANDEX.DATETIME") {
      if (Entity2Json["year"].count() != 0)
        boost::optional<int> year = Entity2Json["year"];
      if (Entity2Json["month"].count() != 0)
        boost::optional<int> month = Entity2Json["month"];
      if (Entity2Json["day"].count() != 0)
        boost::optional<int> day = Entity2Json["day"];
      if (Entity2Json["hour"].count() != 0)
        boost::optional<int> hour = Entity2Json["hour"];
      if (Entity2Json["minute"].count() != 0)
        boost::optional<int> minute = Entity2Json["minute"];
      if (Entity2Json["year_is_relative"].count() != 0)
        boost::optional<bool> yearisrelative = Entity2Json["year_is_relative"];
      if (Entity2Json["month_is_relative"].count() != 0)
        boost::optional<bool> monthisrelative =
            Entity2Json["month_is_relative"];
      if (Entity2Json["day_is_relative"].count() != 0)
        boost::optional<bool> dayisrelative = Entity2Json["day_is_relative"];
      if (Entity2Json["hour_is_relative"].count() != 0)
        boost::optional<bool> year = Entity2Json["hour_is_relative"];
      if (Entity2Json["minute_is_relative"].count() != 0)
        boost::optional<bool> minuteisrelative =
            Entity2Json["minute_is_relative"];
      Value value2(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none, year,
                   month, day, hour, minute, yearisrelative, monthisrelative,
                   dayisrelative, hourisrelative, minuteisrelative,
                   boost::none);
      Entity entity2(Token2, value2, Entity2Json["type"]);
      entities[1] = entity2;
    }
    if (Entity2Json["type"] == "YANDEX.NUMBER") {
      if (Entity2Json["value"].count() != 0)
        boost::optional<float> value = Entity2Json["value"];
      Value value2(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, value);
      Entity entity2(Token2, value2, Entity2Json["type"]);
      entities[1] = entity2;
    }
  }

  if (EntitiesJson[2].count() != 0) { // работает ли для массива эта функция?
    auto Entity3Json = EntitiesJson[2];
    auto Token3Json = Entity3Json["tokens"];
    Tokens Token3(boost::none, Token3Json["start"], Token3Json["end"]);
    if (Entity3Json["type"] == "YANDEX.GEO")) {
        if (Entity3Json["country"].count() != 0)
          boost::optional < std : string > country = Entity3Json["country"];
        if (Entity3Json["city"].count() != 0)
          boost::optional < std : string > city = Entity3Json["city"];
        if (Entity3Json["street"].count() != 0)
          boost::optional < std : string > street = Entity3Json["street"];
        if (Entity3Json["house_numer"].count() != 0)
          boost::optional<unsigned> house_number = Entity3Json["house_number"];
        if (Entity3Json["airport"].count() != 0)
          boost::optional < std : string > airport = Entity3Json["airport"];
        Value value3(boost::none, boost::none, boost::none, country, city,
                     street, house_number, airport, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none);
        Entity entity3(Token3, value3, Entity3Json["type"]);
        entities[2] = entity3;
      }
    if (Entity3Json["type"] == "YANDEX.FIO") {
      if (Entity3Json["first_name"].count() != 0)
        boost::optional < std : string > first_name = Entity3Json["first_name"];
      if (Entity3Json["patronymic_name"].count() != 0)
        boost::optional < std : string > patronymic_name =
            Entity3Json["patronymic_name"];
      if (Entity3Json["last_name"].count() != 0)
        boost::optional < std : string > last_name = Entity3Json["last_name"];
      Value value3(first_name, patronymic_name, last_name, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none);
      Entity entity3(Token3, value3, Entity3Json["type"]);
      entities[2] = entity3;
    }
    if (Entity3Json["type"] == "YANDEX.DATETIME") {
      if (Entity3Json["year"].count() != 0)
        boost::optional<int> year = Entity3Json["year"];
      if (Entity3Json["month"].count() != 0)
        boost::optional<int> month = Entity3Json["month"];
      if (Entity3Json["day"].count() != 0)
        boost::optional<int> day = Entity3Json["day"];
      if (Entity3Json["hour"].count() != 0)
        boost::optional<int> hour = Entity3Json["hour"];
      if (Entity3Json["minute"].count() != 0)
        boost::optional<int> minute = Entity3Json["minute"];
      if (Entity3Json["year_is_relative"].count() != 0)
        boost::optional<bool> yearisrelative = Entity3Json["year_is_relative"];
      if (Entity3Json["month_is_relative"].count() != 0)
        boost::optional<bool> monthisrelative =
            Entity3Json["month_is_relative"];
      if (Entity3Json["day_is_relative"].count() != 0)
        boost::optional<bool> dayisrelative = Entity3Json["day_is_relative"];
      if (Entity3Json["hour_is_relative"].count() != 0)
        boost::optional<bool> year = Entity3Json["hour_is_relative"];
      if (Entity3Json["minute_is_relative"].count() != 0)
        boost::optional<bool> minuteisrelative =
            Entity3Json["minute_is_relative"];
      Value value3(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none, year,
                   month, day, hour, minute, yearisrelative, monthisrelative,
                   dayisrelative, hourisrelative, minuteisrelative,
                   boost::none);
      Entity entity3(Token3, value3, Entity3Json["type"]);
      entities[2] = entity3;
    }
    if (Entity3Json["type"] == "YANDEX.NUMBER") {
      if (Entity3Json["value"].count() != 0)
        boost::optional<float> value = Entity3Json["value"];
      Value value3(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, value);
      Entity entity3(Token3, value3, Entity3Json["type"]);
      entities[2] = entity3;
    }
  }

  if (EntitiesJson[3].count() != 0) { // работает ли для массива эта функция?
    auto Entity4Json = EntitiesJson[3];
    auto Token4Json = Entity4Json["tokens"];
    Tokens Token4(boost::none, Token4Json["start"], Token4Json["end"]);
    if (Entity4Json["type"] == "YANDEX.GEO")) {
        if (Entity4Json["country"].count() != 0)
          boost::optional < std : string > country = Entity4Json["country"];
        if (Entity4Json["city"].count() != 0)
          boost::optional < std : string > city = Entity4Json["city"];
        if (Entity4Json["street"].count() != 0)
          boost::optional < std : string > street = Entity4Json["street"];
        if (Entity4Json["house_numer"].count() != 0)
          boost::optional<unsigned> house_number = Entity4Json["house_number"];
        if (Entity4Json["airport"].count() != 0)
          boost::optional < std : string > airport = Entity4Json["airport"];
        Value value4(boost::none, boost::none, boost::none, country, city,
                     street, house_number, airport, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none, boost::none, boost::none, boost::none,
                     boost::none);
        Entity entity4(Token4, value4, Entity4Json["type"]);
        entities[3] = entity4;
      }
    if (Entity4Json["type"] == "YANDEX.FIO") {
      if (Entity4Json["first_name"].count() != 0)
        boost::optional < std : string > first_name = Entity4Json["first_name"];
      if (Entity4Json["patronymic_name"].count() != 0)
        boost::optional < std : string > patronymic_name =
            Entity4Json["patronymic_name"];
      if (Entity4Json["last_name"].count() != 0)
        boost::optional < std : string > last_name = Entity4Json["last_name"];
      Value value4(first_name, patronymic_name, last_name, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none);
      Entity entity4(Token4, value4, Entity4Json["type"]);
      entities[3] = entity4;
    }
    if (Entity4Json["type"] == "YANDEX.DATETIME") {
      if (Entity4Json["year"].count() != 0)
        boost::optional<int> year = Entity4Json["year"];
      if (Entity4Json["month"].count() != 0)
        boost::optional<int> month = Entity4Json["month"];
      if (Entity4Json["day"].count() != 0)
        boost::optional<int> day = Entity4Json["day"];
      if (Entity4Json["hour"].count() != 0)
        boost::optional<int> hour = Entity4Json["hour"];
      if (Entity4Json["minute"].count() != 0)
        boost::optional<int> minute = Entity4Json["minute"];
      if (Entity4Json["year_is_relative"].count() != 0)
        boost::optional<bool> yearisrelative = Entity4Json["year_is_relative"];
      if (Entity4Json["month_is_relative"].count() != 0)
        boost::optional<bool> monthisrelative =
            Entity4Json["month_is_relative"];
      if (Entity4Json["day_is_relative"].count() != 0)
        boost::optional<bool> dayisrelative = Entity4Json["day_is_relative"];
      if (Entity4Json["hour_is_relative"].count() != 0)
        boost::optional<bool> year = Entity4Json["hour_is_relative"];
      if (Entity4Json["minute_is_relative"].count() != 0)
        boost::optional<bool> minuteisrelative =
            Entity4Json["minute_is_relative"];
      Value value4(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none, year,
                   month, day, hour, minute, yearisrelative, monthisrelative,
                   dayisrelative, hourisrelative, minuteisrelative,
                   boost::none);
      Entity entity4(Token4, value4, Entity4Json["type"]);
      entities[3] = entity4;
    }
    if (Entity4Json["type"] == "YANDEX.NUMBER") {
      if (Entity4Json["value"].count() != 0)
        boost::optional<float> value = Entity4Json["value"];
      Value value4(boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, boost::none, boost::none,
                   boost::none, boost::none, value);
      Entity entity4(Token4, value4, Entity4Json["type"]);
      entities[3] = entity4;
    }
  }
}
} // namespace

const Meta &Request::Meta() const { return meta; }
const Session &Request::Session() const { return session; }
const std::srting &Request::Version() const { return version; }
std::string Request::Command() const { return command; }
std::string Request::OriginalUtterance() const { return originalutterance; }
RequestType Request::Type() const { return type; }
boost::optional<bool> Request::IsDangerousContext() const {
  return isdangerouscontext;
}
std::string Request::Payload() const { return payload; }
Tokens Request::StrToken() const { return strtoken; }
std::vector<boost::optional<Entity>> Request::Entities() { return entities; }