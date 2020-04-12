#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

#include <string>
using namespace std;

TEST_CASE("addFather&addMother&relation") {

    Tree T("rinat");
    T.addFather("rinat", "ravit")
    T.addMother("rinat", "rafi");
    CHECK(T.relation("rinat") == string("me"));
    CHECK(T.relation("rafi") == string("father"));
    CHECK(T.relation("ravit") == string("mother"));

    CHECK_THROWS(T.addFather("rinat", "jfj"));
    CHECK_THROWS(T.addMother("rinat", "fjdjdf"));

    T.addMother("ravit", "mazal")
    T.addFather("ravit", "moshe");
    CHECK(T.relation("mazal") == string("grandmother"));
    CHECK(T.relation("moshe") == string("grandfather"));
    CHECK_THROWS(T.addMother("ravit", "fkfkf"));
    CHECK_THROWS(T.addFather("ravit", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("rafi", "ibo")
    T.addMother("rafi", "rina");
    CHECK(T.relation("ibo") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("rafi", "mcmc"));
    CHECK_THROWS(T.addMother("rafi", "cjcjcj"));

    T.addFather("ibo", "ibof")
    T.addMother("ibo", "ibom");
    CHECK(T.relation("ibof") == string("great-grandfather"));
    CHECK(T.relation("ibom") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("ibo", "mcmc"));
    CHECK_THROWS(T.addMother("ibo", "cjcjcj"));

    T.addFather("ibom", "ibomf")
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

 TEST_CASE("addFather&addMother&find") {

    Tree T("rinat");
    T.addFather("rinat", "ravit")
    T.addMother("rinat", "rafi");
    CHECK(T.find("me") == string("rinat"));
    CHECK(T.find("father") == string("rafi"));
    CHECK(T.find("mother") == string("ravit"));

    T.addMother("ravit", "mazal")
    T.addFather("ravit", "moshe");
    CHECK(T.find("grandmother") == string("mazal"));
    CHECK(T.find("grandfather") == string("moshe"));

    T.addFather("mazal", "moshe1")
    T.addMother("mazal", "rivka");
    CHECK(T.find("great-grandfather") == string("moshe1"));
    CHECK(T.find("great-grandmother") == string("rivka"));


    T.addFather("rivka", "name")
    T.addMother("rivka", "name1");
    CHECK(T.find("great-great-grandfather") == string("name"));
    CHECK(T.find("great-great-grandmother") == string("name1"));

    CHECK_THROWS(T.find("Uncle"));
    CHECK_THROWS(T.find("grand"));
    CHECK_THROWS(T.find("jjffj"));
    CHECK_THROWS(T.find("g");
}

TEST_CASE("Test 1 remove") {

    Tree T("rinat");
    T.addMother("rinat", "ravit");
    T.addFather("rinat", "rafi");
    T.addMother("ravit", "mazal");
    T.addFather("ravit", "moshe");
    T.addMother("mazal", "rivka");
    T.addMother("mazal", "simha");


    CHECK_THROWS(T.remove("rinat")); //exception
    CHECK(T.find("grandfather") == string("moshe"));
    CHECK(T.find("grandmother") == string("mazal"));
    T.remove("mazal");
    CHECK_THROWS(T.find("grandmother"));
    CHECK_THROWS(T.find("great-grandmother"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    T.remove("rafi");
    CHECK_THROWS(T.find("rafi"));
}

TEST_CASE("Test 2 remove") 
{
    Tree T("Ori");
    T.addMother("Ori", "Hanna");
    T.addFather("Ori", "Avi");
    T.addMother("Hanna", "Haya");
    T.addFather("Hanna", "Moshe");
    T.addMother("Moshe", "Calanit");
    T.addFather("Moshe", "Moky");
    T.addFather("Avi", "Moshe1");

    CHECK_THROWS(T.remove("Ori")); // exception
    CHECK((T.find("grandfather") == string("Moshe1") || T.find("grandfather") == string("Moshe")));
    CHECK(T.find("father") == string("Avi"));
    T.remove("Avi");
    CHECK_THROWS(T.find("father"));
    CHECK(T.find("grandfather") == string("Moshe")); 
    CHECK(T.find("great-grandmother") == string("Calanit"));
    CHECK(T.find("great-grandfather") == string("Moky"));
    T.remove("Calanit");
    CHECK_THROWS(T.find("great-grandmother"));
    T.remove("Moshe");
    CHECK_THROWS(T.find("great-grandfather"));
    T.addFather("Hanna", "Nissan"); 
    CHECK(T.find("grandfather") == string("Moshe"));
    CHECK(T.find("grandmother") == string("Haya"));
}