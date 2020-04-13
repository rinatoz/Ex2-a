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


TEST_CASE("addFather&addMother&relation&find") 
{
    Tree T("lin");
    T.addFather("lin", "mishel");
    T.addMother("lin", "sharon");
    CHECK(T.relation("lin") == string("me"));
    CHECK(T.relation("mishel") == string("father"));
    CHECK(T.relation("sharon") == string("mother"));

    CHECK_THROWS(T.addFather("lin", "jfj"));
    CHECK_THROWS(T.addMother("lin", "fjdjdf"));

    T.addMother("sharon", "kim");
    T.addFather("sharon", "may");
    CHECK(T.relation("kim") == string("grandmother"));
    CHECK(T.relation("may") == string("grandfather"));
    CHECK_THROWS(T.addMother("sharon", "fkfkf"));
    CHECK_THROWS(T.addFather("sharon", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("mishel", "noy");
    T.addMother("mishel", "noya");
    CHECK(T.find("grandfather") == string("noy"));
    CHECK(T.find("grandmother") == string("noya"));
    CHECK_THROWS(T.addFather("mishel", "mcmc"));
    CHECK_THROWS(T.addMother("mishel", "cjcjcj"));

    T.addFather("noy", "noyf");
    T.addMother("noy", "noym");
    CHECK(T.find("great-grandfather") == string("noyf"));
    CHECK(T.find("great-grandmother") == string("noym"));
    CHECK_THROWS(T.addFather("noy", "mcmc"));
    CHECK_THROWS(T.addMother("noy", "cjcjcj"));

    T.addFather("noym", "noymf");
    T.addMother("noym", "noymm");
    CHECK(T.find("great-great-grandfather") == string("noymf"));
    CHECK(T.find("great-great-grandmother") == string("noymm"));
    CHECK_THROWS(T.addFather("noym", "mcmc"));
    CHECK_THROWS(T.addMother("noym", "cjcjcj"));

    CHECK(T.relation("ron") == string("unrelated"));
    CHECK(T.relation("beny") == string("unrelated"));
    CHECK(T.relation("daniela") == string("unrelated"));
    CHECK(T.relation("aviv") == string("unrelated"));
    CHECK(T.relation("neaama") == string("unrelated"));
    CHECK(T.relation("hfhf0") == string("unrelated"));
    CHECK(T.relation("tfjfjf") == string("unrelated"));
    CHECK(T.relation("afjfjmit") == string("unrelated"));
    CHECK(T.relation("nafkfkti") == string("unrelated"));
    CHECK(T.relation("or") == string("unrelated"));
}
TEST_CASE("addFather&addMother&relation3") 
{
    Tree T("shay");
    T.addFather("shay", "menashe");
    T.addMother("shay", "yaffa");
    CHECK(T.relation("shay") == string("me"));
    CHECK(T.relation("menashe") == string("father"));
    CHECK(T.relation("yaffa") == string("mother"));

    CHECK_THROWS(T.addFather("shay", "jfj"));
    CHECK_THROWS(T.addMother("shay", "fjdjdf"));

    T.addMother("yaffa", "may");
    T.addFather("yaffa", "rahum");
    CHECK(T.relation("may") == string("grandmother"));
    CHECK(T.relation("rahum") == string("grandfather"));
    CHECK_THROWS(T.addMother("yaffa", "fkfkf"));
    CHECK_THROWS(T.addFather("yaffa", "fjfjfj"));
    CHECK_THROWS(T.addFather("notexist", "jfjjffj")); 

    T.addFather("menashe", "yakov");
    T.addMother("menashe", "rina");
    CHECK(T.relation("yakov") == string("grandfather"));
    CHECK(T.relation("rina") == string("grandmother"));
    CHECK_THROWS(T.addFather("menashe", "mcmc"));
    CHECK_THROWS(T.addMother("menashe", "cjcjcj"));

    T.addFather("yakov", "yakovf");
    T.addMother("yakov", "yakovm");
    CHECK(T.relation("yakovf") == string("great-grandfather"));
    CHECK(T.relation("yakovm") == string("great-grandmother"));
    CHECK_THROWS(T.addFather("yakov", "mcmc"));
    CHECK_THROWS(T.addMother("yakov", "cjcjcj"));

    T.addFather("yakovm", "yakovmf");
    T.addMother("yakovm", "yakovmm");
    CHECK(T.relation("yakovmf") == string("great-great-grandfather"));
    CHECK(T.relation("yakovmm") == string("great-great-grandmother"));
    CHECK_THROWS(T.addFather("yakovm", "mcmc"));
    CHECK_THROWS(T.addMother("yakovm", "cjcjcj"));

    CHECK(T.relation("rina") ==ie string("unrelated"));
    CHECK(T.relation("eden") ==edenring("unrelated"));
    CHECK(T.relation("daniel") == stvring("unrelated"));
    CHECK(T.relation("noy") == string("unrelated"));
    CHECK(T.relation("yossi") == string("unrelated"));
    CHECK(T.relation("0") == string("unrelated"));
    CHECK(T.relation("t") == string("unrelated"));
    CHECK(T.relation("amit") == string("unrelated"));
    CHECK(T.relation("nati") == string("unrelated"));
    CHECK(T.relation("yossef") == string("unrelated"));
}
