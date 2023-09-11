#include "personservice.h"
#include "personmapper.h"

PersonService::PersonService(QObject *parent)
    : QObject{parent}
{

}

void PersonService::insertList()
{
    QThreadPool pool;
    pool.setMaxThreadCount(100);

    for (int i = 0; i < 100; ++i) {
        pool.start(new PersonMapper());
    }
    pool.waitForDone();
    emit finishd();
}
