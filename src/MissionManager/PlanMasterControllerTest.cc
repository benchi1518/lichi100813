/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "PlanMasterControllerTest.h"
#include "LinkManager.h"
#include "MultiVehicleManager.h"
#include "SimpleMissionItem.h"
#include "MissionSettingsItem.h"
#include "QGCApplication.h"
#include "SettingsManager.h"
#include "AppSettings.h"

PlanMasterControllerTest::PlanMasterControllerTest(void)
    : _masterController(NULL)
{
    
}

void PlanMasterControllerTest::init(void)
{
    UnitTest::init();

    _masterController = new PlanMasterController(this);
    _masterController->start(true /* editMode */);
}

void PlanMasterControllerTest::cleanup(void)
{
    delete _masterController;
    _masterController = NULL;

    UnitTest::cleanup();
}

void PlanMasterControllerTest::_testMissionFileLoad(void)
{
    _masterController->loadFromFile(":/json/unittest/OldFileFormat.mission");
    QCOMPARE(_masterController->missionController()->visualItems()->count(), 7);
}


void PlanMasterControllerTest::_testMissionPlannerFileLoad(void)
{
    _masterController->loadFromFile(":/json/unittest/MissionPlanner.waypoints");
    QCOMPARE(_masterController->missionController()->visualItems()->count(), 6);
}
