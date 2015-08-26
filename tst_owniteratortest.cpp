#include <QString>
#include <QTextStream>
#include <QtTest>

#include "owncontainer.h"

#include <boost/foreach.hpp>

class OwnIteratorTest : public QObject
{
    Q_OBJECT

public:
    OwnIteratorTest();

private Q_SLOTS:
    void testClassicLoopFor();
    void testLoopForC11();
    void testBoostForEach();
    void testLoopForWithModification();
    void testCopy();
    void testFind();
};

template<typename Container>
QString makeString(Container& cont)
{
    QString result = "";
    QTextStream stream(&result);
    bool first = true;
    for(auto& i: cont)
    {
        if(first)
        {
            first = false;
            stream << i;
        }
        else
        {
            stream << "," << i;
        }
    }
    return result;
}

OwnIteratorTest::OwnIteratorTest()
{
}

void OwnIteratorTest::testClassicLoopFor()
{
    QString result = "";
    QTextStream stream(&result);
    OwnContainer container = {0, 1, 2, 3};
    for(OwnContainer::iterator it = container.begin(); it != container.end(); ++it)
        stream << *it << ",";
    QCOMPARE(result, QString("0,1,2,3,"));
}


void OwnIteratorTest::testLoopForC11()
{
    QString result = "";
    QTextStream stream(&result);
    OwnContainer container = {0, 1, 2, 3};
    for(auto i: container)
        stream << i << ",";
    QCOMPARE(result, QString("0,1,2,3,"));
}

void OwnIteratorTest::testBoostForEach()
{
    QString result = "";
    QTextStream stream(&result);
    OwnContainer container = {0, 1, 2, 3};
    BOOST_FOREACH(auto i, container)
        stream << i << ",";
    QCOMPARE(result, QString("0,1,2,3,"));
}

void OwnIteratorTest::testLoopForWithModification()
{
    OwnContainer container = {0, 1, 2, 3};
    for(auto& i: container)
        ++i;
    QCOMPARE(makeString(container), QString("1,2,3,4"));
}

void OwnIteratorTest::testCopy()
{
    OwnContainer src  = {1,2,3,4};
    OwnContainer dest = {0,0,0,0,0,0};
    QCOMPARE(makeString(dest), QString("0,0,0,0,0,0"));
    std::copy(src.begin(),src.end(),dest.begin());
    QCOMPARE(makeString(dest), QString("1,2,3,4,0,0"));
}

void OwnIteratorTest::testFind()
{
    OwnContainer container = {0, 1, 2, 3};
    const int looked = 2;
    OwnContainer::iterator it = std::find(container.begin(), container.end(), looked);
    QVERIFY(it != container.end());
    QCOMPARE(*it, looked);
}

QTEST_APPLESS_MAIN(OwnIteratorTest)

#include "tst_owniteratortest.moc"
