/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// If empty string is passed as operation name
// function should return nothing
TEST(GoalUndoTest, checkForBlankOperationName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("firstGoal","");

	ASSERT_EQ("",goalUndoObj.getGoal());
}

//It is used to test whether passed goal and operations are added
TEST(GoalUndoTest, checkForValidOperationAndGoalNameAdded)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("firstGoal","firstOperation");

	ASSERT_EQ("firstGoal",goalUndoObj.getGoal());
}

// If empty string is passed as Goal name
// function should return nothing
TEST(GoalUndoTest, checkForBlankGoalName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("","firstOperation");

	ASSERT_EQ("",goalUndoObj.getGoal());
}

//If blank Goal Name and Blank Opertion name is passed
//The function should return nothing
TEST(GoalUndoTest, checkAddOperationWithBlankGoalAndOperationName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("","");

	ASSERT_EQ("",goalUndoObj.getGoal());
}

//This function is used to check whether valid operation is getting added
TEST(GoalUndoTest, checkAllAddOpeartionsWithValidParameters)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.addOperation("operation2");

	ASSERT_EQ("operation1 operation2",goalUndoObj.getOperations());
}


TEST(GoalUndoTest, checkForAddOp2WithNoGoalName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("operation2");

	ASSERT_EQ("operation2",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, checkForTwoAddOpeartionsWithOneEmptyOperationName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.addOperation("");

	ASSERT_EQ("operation1",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForAddOp2WithNoOperationName)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("");

	ASSERT_EQ("",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForUndoOperationWithNoOperation)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("operation1");
  goalUndoObj.undoOperation();

  ASSERT_EQ("",goalUndoObj.getOperations());
	ASSERT_EQ("",goalUndoObj.getGoal());
}


TEST(GoalUndoTest, checkForUndoOperation)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.undoOperation();

	ASSERT_EQ("",goalUndoObj.getOperations());
}

//It is used to check whether latest added goal will be
//returned from getGoal function
TEST(GoalUndoTest, checkForGetGoal)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
	goalUndoObj.addOperation("goal2","operation2");

  ASSERT_EQ("goal2",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, getGoalNoGoalCheck)
{
  GoalUndo goalUndoObj;

  ASSERT_EQ("",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, checkForGetOperations)
{
  GoalUndo goalUndoObj;

  ASSERT_EQ("",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForGetOperationsWithOneOperation)
{
  GoalUndo goalUndoObj;
	goalUndoObj.addOperation("goal1","operation1");

  ASSERT_EQ("operation1",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForNormalUndoOperation2)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.undoOperation("operation1");

  ASSERT_EQ("",goalUndoObj.getOperations());

}


TEST(GoalUndoTest, checkForUndoOpertaion2WithNoGoal)
{
  GoalUndo goalUndoObj;

  ASSERT_EQ("",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, checkForGetOperationsWithValidParameters)
{
  GoalUndo goalUndoObj;
	goalUndoObj.addOperation("goal1","operation1");
	goalUndoObj.addOperation("operation2");
	goalUndoObj.addOperation("operation3");

  ASSERT_EQ("operation1 operation2 operation3",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkUndoOpertaion2ForOperations)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.addOperation("operation2");
	goalUndoObj.undoOperation("operation1");

  ASSERT_EQ("operation2",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForUndoOperationWithNoGoal)
{
  GoalUndo goalUndoObj;
  goalUndoObj.undoOperation();

	ASSERT_EQ("",goalUndoObj.getOperations());
}


TEST(GoalUndoTest, checkForUndoGoal)
{
  GoalUndo goalUndoObj;
	goalUndoObj.addOperation("goal1","operation1");
	goalUndoObj.undoGoal();

  ASSERT_EQ("",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, checkForUndoGoalWithNoGoal)
{
  GoalUndo goalUndoObj;
	goalUndoObj.undoGoal();

  ASSERT_EQ("",goalUndoObj.getOperations());
}

TEST(GoalUndoTest, checkForUndoOpertaion2WithGoalOnly)
{
  GoalUndo goalUndoObj;
  goalUndoObj.addOperation("goal1","operation1");
  goalUndoObj.undoOperation("operation1");

  ASSERT_EQ("",goalUndoObj.getGoal());
}

TEST(GoalUndoTest, checkUndoGoalForOperations)
{
  GoalUndo goalUndoObj;
	goalUndoObj.addOperation("goal1","operation1");
	goalUndoObj.undoGoal();

  ASSERT_EQ("",goalUndoObj.getOperations());
}
