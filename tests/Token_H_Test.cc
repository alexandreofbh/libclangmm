#include <boost/test/unit_test.hpp>
#include "clangmm.h"
#include <string>

BOOST_AUTO_TEST_CASE(token) {
  std::string path("./case/main.cpp");

  clangmm::Index index(0, 0);

  clangmm::TranslationUnit tu(index, path, {});
  
  auto tokens=tu.get_tokens(0, 113);

  BOOST_CHECK(tokens->size() == 32);
  BOOST_CHECK((*tokens)[1].get_kind() == clangmm::Token::Kind::Identifier);

  std::string str = (*tokens)[28].get_spelling();
  BOOST_CHECK(str == "return");  
}
