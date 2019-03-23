//
// Created by ward on 3/23/19.
//
//TODO header

#include <gtest/gtest.h>
#include "../parsers/VAbstractParser.h"

class NetworkParserTester : public ::testing::Test {
protected:
    friend class VAbstractParser;
    virtual void SetUp() {}

    virtual void TearDown() {}

};

TEST_F(NetworkParserTester, LoadFile) {
    VAbstractParser parser;
    EXPECT_DEATH(parser.loadFile(""), "Failed to load file: no filename");
    EXPECT_DEATH(parser.loadFile("FakeFile"), "Assertion `Failed to open file' failed.");
}

TEST_F(NetworkParserTester, GetRoot) {
    VAbstractParser parser;
    EXPECT_DEATH(parser.getRoot(), "Failed to get root: no root element");
}

TEST_F(NetworkParserTester, ReadElement) {
    VAbstractParser parser;
    EXPECT_DEATH(parser.readElement(NULL, "FakeElement"), "Failed to read element: no element");
    parser.loadFile("inputfiles/testinputs/test1.xml");
    EXPECT_STREQ(parser.readElement(parser.getRoot(), "FakeElement").c_str(), "");
    EXPECT_DEATH(parser.readElement(parser.getRoot(), ""), "Failed to read element: no tag");
}

TEST_F(NetworkParserTester, Clear) {
    VAbstractParser parser;
    parser.loadFile("inputfiles/testinputs/test1.xml");
    parser.clear();
    EXPECT_DEATH(parser.getRoot(), "Failed to get root: no root element");
}

