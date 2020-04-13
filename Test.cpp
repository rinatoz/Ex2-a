#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

#include <string>
using namespace std;

TEST_CASE("addFather&addMother&relation") 
{
    Tree T("rinat");
    T.addFather("rinat", "rafi");
    T.addMother("rinat", "ravit");
    CHECK(T.relation("rinat") == string("me"));
    CHECK(T.relation("rafi") == string("father"));
    CHECK(T.relation("ravit") == string("mother"));

    CHECK_THROWS(T.addFather("rinat", "jfj"));
    CHECK_THROWS(T.addMother("rinat", "fjdjdf"));

    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    CHECK(T.relation("mazal") == string("grandmother"));
    CHECK(T.relation("moshe") == string("grandfather"));
    CHECK_THROWS(T.addMother("ravit", "fkfkf"));
    CHECK_THROWS(T.addFather("ravit", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("rafi", "ibo");
    T.addMother("rafi", "rina");
    CHECK(T.relation("ibo") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("rafi", "mcmc"));
    CHECK_THROWS(T.addMother("rafi", "cjcjcj"));

    T.addFather("ibo", "ibof");
    T.addMother("ibo", "ibom");
    CHECK(T.relation("ibof") == string("great-grandfather"));
    CHECK(T.relation("ibom") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("ibo", "mcmc"));
    CHECK_THROWS(T.addMother("ibo", "cjcjcj"));

    T.addFather("ibom", "ibomf");
    T.addMother("ibom", "ibomm");
    CHECK(T.relation("ibomf") == string("great-great-grandfather"));
    CHECK_THROWS(T.addFather("ibom", "mcmc"));
    CHECK_THROWS(T.addMother("ibom", "cjcjcj"));

    CHECK(T.relation("rin") == string("unrelated"));
    CHECK(T.relation("ben") == string("unrelated"));
    CHECK(T.relation("daniel") == string("unrelated"));
    CHECK(T.relation("roy") == string("unrelated"));
    CHECK(T.relation("yossi") == string("unrelated"));
    CHECK(T.relation("0") == string("unrelated"));
    CHECK(T.relation("t") == string("unrelated"));
    CHECK(T.relation("amit") == string("unrelated"));
    CHECK(T.relation("nati") == string("unrelated"));
    CHECK(T.relation("yossef") == string("unrelated"));
}

 TEST_CASE("addFather&addMother&find") {

    Tree T("rinat");
    T.addFather("rinat", "rafi");
    T.addMother("rinat", "ravit");
    CHECK(T.find("me") == string("rinat"));
    CHECK(T.find("father") == string("rafi"));
    CHECK(T.find("mother") == string("ravit"));

    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    CHECK(T.find("grandmother") == string("mazal"));
    CHECK(T.find("grandfather") == string("moshe"));

    T.addFather("moshe", "moshe1");
    T.addMother("moshe", "rivka");
    CHECK(T.find("great-grandfather") == string("moshe1"));
    CHECK(T.find("great-grandmother") == string("rivka"));


    T.addFather("rivka", "name");
    T.addMother("rivka", "name1");
    CHECK(T.find("great-great-grandfather") == string("name"));
    CHECK(T.find("great-great-grandmother") == string("name1"));
}


TEST_CASE("Test 3") 
{
    Tree T("idan");
    T.addMother("idan", "ravit");
    T.addFather("idan", "rafi");
    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    T.addMother("moshe", "ilanit");
    T.addFather("moshe", "igal");

    CHECK_THROWS(T.remove("idan")); // exception
    CHECK(T.find("grandfather") == string("moshe"));
    CHECK(T.find("father") == string("rafi"));
    T.remove("rafi");
    CHECK_THROWS(T.find("father"));
    CHECK(T.find("grandfather") == string("moshe")); 
    CHECK(T.find("great-grandmother") == string("ilanit"));
    CHECK(T.find("great-grandfather") == string("igal"));
    T.remove("ilanit");
    CHECK_THROWS(T.find("great-grandmother"));
}
TEST_CASE("addFather&addMother&relation2") 
{
    Tree T("rinat");
    T.addFather("rinat", "rafi");
    T.addMother("rinat", "ravit");
    CHECK(T.relation("rinat") == string("me"));
    CHECK(T.relation("rafi") == string("father"));
    CHECK(T.relation("ravit") == string("mother"));

    CHECK_THROWS(T.addFather("rinat", "jfj"));
    CHECK_THROWS(T.addMother("rinat", "fjdjdf"));

    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    CHECK(T.relation("mazal") == string("grandmother"));
    CHECK(T.relation("moshe") == string("grandfather"));
    CHECK_THROWS(T.addMother("ravit", "fkfkf"));
    CHECK_THROWS(T.addFather("ravit", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("rafi", "ibo");
    T.addMother("rafi", "rina");
    CHECK(T.relation("ibo") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("rafi", "mcmc"));
    CHECK_THROWS(T.addMother("rafi", "cjcjcj"));

    T.addFather("ibo", "ibof");
    T.addMother("ibo", "ibom");
    CHECK(T.relation("ibof") == string("great-grandfather"));
    CHECK(T.relation("ibom") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("ibo", "mcmc"));
    CHECK_THROWS(T.addMother("ibo", "cjcjcj"));

    T.addFather("ibom", "ibomf");
    T.addMother("ibom", "ibomm");
    CHECK(T.relation("ibomf") == string("great-great-grandfather"));
    CHECK(T.relation("ibomm") == string("great-great-grandmother"));
    CHECK_THROWS(T.addFather("ibom", "mcmc"));
    CHECK_THROWS(T.addMother("ibom", "cjcjcj"));

    CHECK(T.relation("rin") == string("unrelated"));
    CHECK(T.relation("ben") == string("unrelated"));
    CHECK(T.relation("daniel") == string("unrelated"));
    CHECK(T.relation("roy") == string("unrelated"));
    CHECK(T.relation("yossi") == string("unrelated"));
    CHECK(T.relation("0") == string("unrelated"));
    CHECK(T.relation("t") == string("unrelated"));
    CHECK(T.relation("amit") == string("unrelated"));
    CHECK(T.relation("nati") == string("unrelated"));
    CHECK(T.relation("yossef") == string("unrelated"));
}
TEST_CASE("addFather&addMother&relation1") 
{
    Tree T("rinat");
    T.addFather("rinat", "rafi");
    T.addMother("rinat", "ravit");
    CHECK(T.relation("rinat") == string("me"));
    CHECK(T.relation("rafi") == string("father"));
    CHECK(T.relation("ravit") == string("mother"));

    CHECK_THROWS(T.addFather("rinat", "jfj"));
    CHECK_THROWS(T.addMother("rinat", "fjdjdf"));

    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    CHECK(T.relation("mazal") == string("grandmother"));
    CHECK(T.relation("moshe") == string("grandfather"));
    CHECK_THROWS(T.addMother("ravit", "fkfkf"));
    CHECK_THROWS(T.addFather("ravit", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("rafi", "ibo");
    T.addMother("rafi", "rina");
    CHECK(T.relation("ibo") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("rafi", "mcmc"));
    CHECK_THROWS(T.addMother("rafi", "cjcjcj"));

    T.addFather("ibo", "ibof");
    T.addMother("ibo", "ibom");
    CHECK(T.relation("ibof") == string("great-grandfather"));
    CHECK(T.relation("ibom") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("ibo", "mcmc"));
    CHECK_THROWS(T.addMother("ibo", "cjcjcj"));

    T.addFather("ibom", "ibomf");
    T.addMother("ibom", "ibomm");
    CHECK(T.relation("ibomf") == string("great-great-grandfather"));
    CHECK(T.relation("ibomm") == string("great-great-grandmother"));
    CHECK_THROWS(T.addFather("ibom", "mcmc"));
    CHECK_THROWS(T.addMother("ibom", "cjcjcj"));

    CHECK(T.relation("rin") == string("unrelated"));
    CHECK(T.relation("ben") == string("unrelated"));
    CHECK(T.relation("daniel") == string("unrelated"));
    CHECK(T.relation("roy") == string("unrelated"));
    CHECK(T.relation("yossi") == string("unrelated"));
    CHECK(T.relation("0") == string("unrelated"));
    CHECK(T.relation("t") == string("unrelated"));
    CHECK(T.relation("amit") == string("unrelated"));
    CHECK(T.relation("nati") == string("unrelated"));
    CHECK(T.relation("yossef") == string("unrelated"));
}
TEST_CASE("addFather&addMother&relation3") 
{
    Tree T("rinat");
    T.addFather("rinat", "rafi");
    T.addMother("rinat", "ravit");
    CHECK(T.relation("rinat") == string("me"));
    CHECK(T.relation("rafi") == string("father"));
    CHECK(T.relation("ravit") == string("mother"));

    CHECK_THROWS(T.addFather("rinat", "jfj"));
    CHECK_THROWS(T.addMother("rinat", "fjdjdf"));

    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    CHECK(T.relation("mazal") == string("grandmother"));
    CHECK(T.relation("moshe") == string("grandfather"));
    CHECK_THROWS(T.addMother("ravit", "fkfkf"));
    CHECK_THROWS(T.addFather("ravit", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("rafi", "ibo");
    T.addMother("rafi", "rina");
    CHECK(T.relation("ibo") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("rafi", "mcmc"));
    CHECK_THROWS(T.addMother("rafi", "cjcjcj"));

    T.addFather("ibo", "ibof");
    T.addMother("ibo", "ibom");
    CHECK(T.relation("ibof") == string("great-grandfather"));
    CHECK(T.relation("ibom") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("ibo", "mcmc"));
    CHECK_THROWS(T.addMother("ibo", "cjcjcj"));

    T.addFather("ibom", "ibomf");
    T.addMother("ibom", "ibomm");
    CHECK(T.relation("ibomf") == string("great-great-grandfather"));
    CHECK(T.relation("ibomm") == string("great-great-grandmother"));
    CHECK_THROWS(T.addFather("ibom", "mcmc"));
    CHECK_THROWS(T.addMother("ibom", "cjcjcj"));

    CHECK(T.relation("rin") == string("unrelated"));
    CHECK(T.relation("ben") == string("unrelated"));
    CHECK(T.relation("daniel") == string("unrelated"));
    CHECK(T.relation("roy") == string("unrelated"));
    CHECK(T.relation("yossi") == string("unrelated"));
    CHECK(T.relation("0") == string("unrelated"));
    CHECK(T.relation("t") == string("unrelated"));
    CHECK(T.relation("amit") == string("unrelated"));
    CHECK(T.relation("nati") == string("unrelated"));
    CHECK(T.relation("yossef") == string("unrelated"));
}
