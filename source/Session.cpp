// Copyright 2018 RomAsya
#include <Session.hpp>

#include <string>
#include <utility>

#include <boost/optional.hpp>

namespace Alice {

Session::Session(size_t message_id,
                 std::string session_id,
                 std::string skill_id,
                 std::string user_id,
                 bool is_new)
    : message_id_(message_id),
      session_id_(std::move(session_id)),
      skill_id_(std::move(skill_id)),
      user_id_(std::move(user_id)),
      is_new_(is_new) {}

}  // namespace Alice
