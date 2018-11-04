#include <Request.hpp>

int main()
{
    std::string data = R"({
      "meta": {
        "locale": "ru-RU",
        "timezone": "Europe/Moscow",
        "client_id": "ru.yandex.searchplugin/5.80"
      },
      "request": {
        "command": "hello my friend",
        "original_utterance": "hello my friend",
        "type": "SimpleUtterance",
        "markup": {
          "dangerous_context": true
        },
        "payload": {}
      },
      "session": {
        "new": true,
        "message_id": 4,
        "session_id": "2eac4854-fce721f3-b845abba-20d60",
        "skill_id": "3ad36498-f5rd-4079-a14b-788652932056",
        "user_id": "AC9WC3DF6FCE052E45A4566A48E6B7193774B84814CE49A922E163B8B29881DC"
      },
      "version": "1.0"
    })";

  Alice::Request request(data);
  std::cout << request.Meta().Locale();
}