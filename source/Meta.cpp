// Copyright 2018 RomAsya
#include <Meta.hpp>

#include <string>
#include <utility>

namespace Alice {

Meta::Meta(std::string locale, std::string timezone, std::string client_id)
    : locale_(std::move(locale)),
      timezone_(std::move(timezone)),
      client_id_(std::move(client_id)) {}

}  // namespace Alice
