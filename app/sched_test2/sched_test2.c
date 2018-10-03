#include <hellfire.h>

void task(void)
{
	int32_t jobs, id;
	id = hf_selfid();
	for (;;)
	{
		jobs = hf_jobs(id);
		printf("\n%s (%d)[%d][%d]", hf_selfname(), id, hf_jobs(id), hf_dlm(id));
		while (jobs == hf_jobs(id))
			;
	}
}



void task_Ap(void)
{
	int32_t jobs, id;
	id = hf_selfid();
	for (;;)
	{
		jobs = hf_jobs(id);	
		printf("\n%s (%d)[%d][%d]", hf_selfname(), id, hf_jobs(id), hf_dlm(id));
		while (jobs == hf_jobs(id))
		;
	}
}


void task_be(void)
{
	int32_t jobs, id;

	id = hf_selfid();
	for (;;)
	{
		int _rand = 50 + ((random() % 499) +1);
		
		delay_ms(_rand);

		hf_spawn(task_Ap, 0, 2, 0, "task aperiodica", 2048);
		jobs = hf_jobs(id);
		printf("\n%s (%d)[%d][%d]", hf_selfname(), id, hf_jobs(id), hf_dlm(id));

		while (jobs == hf_jobs(id))
		;
	}
}


void app_main(void)
{
	int max = 20;
	int i = 0;

	// //Permite que a task aperiódica roda 1 vez  cada 9
	// hf_spawn(task, 0, 5, 0, "task aperiodica", 2048);
	// hf_spawn(task, 10, 9, 10, "task a", 2048); //25%

	//Não permite roda a aperiódica, pois não tem ticks livres
	// hf_spawn(task, 0, 5, 0, "task aperiodica", 2048);
	// hf_spawn(task, 10, 10, 10, "task a", 2048); //25%

	//Teste sugerido (professor)

	int count = 5;
	uint64_t timerInit;
	uint64_t timerEnd;
	
	timerInit = _read_us();

	hf_spawn(task, 4, 2, 4, "task a", 2048);
	hf_spawn(task_be, 0, 0, 0, "task be", 2048);
	
	// while (count)
	// {
	// 	time = _read_us();
	// 	hf_spawn(task, 0, ((random() % 3) + 1), 0, "task aperiodica", 2048);
	// 	count--;
	// }

		
	// hf_spawn(task, 3, 2, 3, "task", 2048);
	// hf_spawn(task, 0, 5, 0, "task aperiodica 1", 2048);
	// hf_spawn(task, 0, 5, 0, "task aperiodica 2", 2048);

	//hf_spawn(task, 8, 2, 8, "task b", 2048); //25%
	//hf_spawn(task, 12, 3, 12, "task c" , 2048); //25%

	/*
	for(i=0; i < max; i++){
		hf_spawn(task, 4, 1, 4, "task "+ i, 2048);
		hf_spawn(task, 8, 2, 8, "task "+ i, 2048);
		hf_spawn(task, 12, 3, 12, "task " + i , 2048);
	} 
*/
}
