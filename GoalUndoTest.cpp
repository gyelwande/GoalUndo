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

TEST(GoalUndoTest, checkForBlankOperationName)
{
  GoalUndo obj;
  obj.addOperation("firstGoal","");
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, checkForValidOperationAndGoalName)
{
  GoalUndo obj;
  obj.addOperation("firstGoal","firstOP");
	ASSERT_EQ("firstGoal",obj.getGoal());
}


TEST(GoalUndoTest, checkForBlankGoalName)
{
  GoalUndo obj;
  obj.addOperation("","firstOp");
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, checkAddOperationWithBlankGoalAndOperationName)
{
  GoalUndo obj;
  obj.addOperation("","");
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, checkAllAddOpeartionsWithValidParameters)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.addOperation("op2");
	ASSERT_EQ("op1 op2",obj.getOperations());
}

TEST(GoalUndoTest, checkForAddOp2WithEmptyGoalName)
{
  GoalUndo obj;
  obj.addOperation("op1");
	ASSERT_EQ("op1",obj.getGoal());
}

TEST(GoalUndoTest, checkForTwoAddOpeartionsWithOneEmptyOperationName)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.addOperation("");
	ASSERT_EQ("op1",obj.getOperations());
}

TEST(GoalUndoTest, checkForAddOp2WithEmptyOperationName)
{
  GoalUndo obj;
  obj.addOperation("");
	ASSERT_EQ("",obj.getOperations());
}

TEST(GoalUndoTest, checkForUndoOperation)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.undoOperation();
	ASSERT_EQ("",obj.getOperations());
}
