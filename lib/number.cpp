#include "number.h"


uint2022_t from_uint(uint32_t i) {
  uint2022_t new_number;
  new_number.explanation[new_number.length] = i % new_number.base;
  new_number.explanation[new_number.length-1] = i / new_number.base;
  return new_number;
}

uint2022_t from_string(const char* buff) {
  uint2022_t new_number;
  std::string string_explanation = std::string(buff);
  for (int i = (int) string_explanation.length(), length = new_number.length; i > 0; i -= 9, length--) {
    if (i < 9) {
      new_number.explanation[length] = (atoi(string_explanation.substr(0, i).c_str()));

    } else {
      new_number.explanation[length] = (atoi(string_explanation.substr(i-9, 9).c_str()));
    }
  }
  return new_number;
}

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
  uint2022_t new_number;
  int64_t accumulator = 0;
  int remains = 0;

  for (int i = new_number.length; i > 0; i--) {
    accumulator = lhs.explanation[i] + rhs.explanation[i];
    new_number.explanation[i] = accumulator % new_number.base + remains;
    remains = accumulator / new_number.base;
  }
  return new_number;
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
  uint2022_t new_number;
  int accumulator = 0;
  int flag = 0;
  for (int i = new_number.length; i > 0; i--) {
    uint32_t left = lhs.explanation[i] + flag;
    uint32_t right = rhs.explanation[i];

    accumulator = left - right;
    if (accumulator < 0) {
      new_number.explanation[i] = new_number.base + accumulator;
      flag = -1;
    } else {
      new_number.explanation[i] = accumulator;
      flag = 0;
    }
  }

  return new_number;
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
  uint2022_t new_number;
  int64_t sub = 0;

  int filled_l = 0;
  int filled_r = 0;

  for (int i = 0; i < lhs.length + 1; i--) {
    if (lhs.explanation[i] != 0) {
      filled_l = 68 - i;
      break;
    }
  }
  for (int i = 0; i < rhs.length + 1; i--) {
    if (rhs.explanation[i] != 0) {
      filled_r = 68 - i;
      break;
    }
  }

  for (int i = 0; i < filled_l; i++) {
    for (int j = 0; j < filled_r || sub != 0; j++) {
      int64_t left_side = lhs.explanation[lhs.length - i];
      int64_t right_side = rhs.explanation[rhs.length - j];

      sub += left_side * right_side + new_number.explanation[new_number.length - (i + j)];
      new_number.explanation[new_number.length - (i + j)] = sub % new_number.base;
      sub /= new_number.base;
    }
  }
  return new_number;
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
  for (int i = lhs.length; i >= 0; i--) {
    if (lhs.explanation[i] != rhs.explanation[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
  std::string output;

  for (int i = 0; i < value.length + 1; i++) {
    if (value.explanation[i] != 0){
      output += std::to_string(value.explanation[i]);
    }
  }
  stream << output;

  return stream;
}
