#include <string>
#include <stdexcept>

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

using namespace std;
class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{

	}

	Result guess(string guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3,0 };
		}

		int solved = false;
		int strikes = getStrikeCount(guessNumber);
		int balls = getBallCount(guessNumber);

		return { false, strikes, balls };
	}

private:
	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber == "")
		{
			throw std::invalid_argument("���� �־����");
		}

		if (guessNumber.length() != 3)
		{
			throw std::invalid_argument("�ڸ��� ����");
		}

		if (isIncludeChar(guessNumber))
		{
			throw std::invalid_argument("���ڷθ� �����Ǿ� ���� ����");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("���� �ߺ� ����");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]) return true;
		if (guessNumber[1] == guessNumber[2]) return true;
		if (guessNumber[2] == guessNumber[0]) return true;
		return false;
	}

	bool isIncludeChar(const string& guessNumber)
	{
		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	int getStrikeCount(string guessNumber)
	{
		int result = 0;

		for (int i = 0;i < 3; ++i)
		{
			int index = question.find(guessNumber[i]);

			if (index == -1) continue;
			if (index != i) continue;

			if (index == i) { result++; }
		}

		return result;
	}

	int getBallCount(string guessNumber)
	{
		int result = 0;

		for (int i = 0;i < 3; ++i)
		{
			int index = question.find(guessNumber[i]);

			if (index == -1) continue;
			if (index != i) continue;
			
			if (index != i) { result++; }
		}

		return result;
	}

private:
	string question;
};