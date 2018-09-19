#include <hellfire.h>


void tarefa(void){
	int32_t jobs, id;

	id = hf_selfid();
	

	//O Resultado hf_freecpu é a sobra de utilização
	//Deadline misses 1 =>  não conseguiu executar a tarefa
	// 8/4 = 50%  12/6 = 50% 20/5 = 25% logo 125%
	for(;;){
		jobs = hf_jobs(id);
		printf("\ntask %d -  %d - Deadline misses %d", id, hf_freecpu(), hf_dlm(id));
		while (jobs == hf_jobs(id));	
	}
		
}



void app_main(void)
{
		int node = 6;


		//hf_spawn(tarefa,p, c, d, "t1", 4096);
		if(node == 1){
			hf_spawn(tarefa, 5, 2, 5, "t1", 1024);
			hf_spawn(tarefa, 7, 3, 7, "t2", 1024);
		}

		if(node == 2){
			hf_spawn(tarefa, 6, 1, 6, "t1", 1024);
			hf_spawn(tarefa, 10, 3, 10, "t2", 1024);
			hf_spawn(tarefa, 16, 4, 16, "t3", 1024);
		}

		if(node == 3){
			hf_spawn(tarefa, 5, 2, 5, "t1", 1024);
			hf_spawn(tarefa, 8, 2, 8, "t2", 1024);
			hf_spawn(tarefa, 12, 2, 12, "t3", 1024);
		}

		if(node == 4){
			hf_spawn(tarefa, 8, 4, 8, "t1", 1024);
			hf_spawn(tarefa, 12, 6, 12, "t2", 1024);
			hf_spawn(tarefa, 20, 5, 5, "t3", 1024);
		}

		if(node == 5){
			hf_spawn(tarefa, 5,  2, 5, "t1", 1024);
			hf_spawn(tarefa, 9,  3, 9, "t2", 1024);
			hf_spawn(tarefa, 20, 1, 20, "t3", 1024);
			hf_spawn(tarefa, 30, 1, 30, "t4", 1024);
		}

		if(node == 6){
			hf_spawn(tarefa, 7,  2, 7, "t1", 1024);
			hf_spawn(tarefa, 8,  1, 8, "t2", 1024);
			hf_spawn(tarefa, 9,  1, 9, "t3", 1024);
			hf_spawn(tarefa, 10, 2, 10, "t4", 1024);
			hf_spawn(tarefa, 13, 1, 13, "t5", 1024);
		}

}

