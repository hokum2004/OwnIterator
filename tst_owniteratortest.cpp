#include <QString>
#include <QtTest>

#include "owncontainer.h"

class OwnIteratorTest : public QObject
{
    Q_OBJECT

public:
    OwnIteratorTest();

private Q_SLOTS:
    void testOutLoopFor();
};

OwnIteratorTest::OwnIteratorTest()
{
}

void OwnIteratorTest::testOutLoopFor()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(OwnIteratorTest)

#include "tst_owniteratortest.moc"
