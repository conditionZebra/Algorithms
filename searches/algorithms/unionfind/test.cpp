#include "result.h"
#include "executor.h"

int main(int argc, char* argv[])
{
	ufExecutor * ex = new ufExecutor();
	ufResult res = ex->execute(argc, argv);

	if(res.errorCode == 0)
	{
		std::cout << "Number of components : " << res.numberOfComponents << std::endl;
		std::cout << "Executinon time: " << res.executinonTime << " milliseconds." << std::endl;
		return 0;
	}
	else
		return res.errorCode;
}
