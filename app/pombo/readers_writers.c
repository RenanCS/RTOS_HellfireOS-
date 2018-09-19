#include <hellfire.h>

#define N_USUARIOS	20
#define N_POMBO	1

sem_t cheia, mutex, enchendo;
int32_t contaPostIt = 0;

void usuario(void){
	while(1){
		
		hf_semwait(&enchendo); // down
		hf_semwait(&mutex); //down
		
		contaPostIt++;

		printf("contaPostIt (%d, tid=%d)  \n", contaPostIt, hf_selfid());
		
		if (contaPostIt==N_USUARIOS)
			hf_sempost(&cheia); // up
		
		hf_sempost(&mutex);
		
	}
}

void pombo(void){
	int32_t i;
	i = hf_selfid();

	while(1){
		hf_semwait(&cheia); // down
		hf_semwait(&mutex); //down
		
		printf("leva_mochila_ate_B_e_volta() thread %d \n",i);
		
		contaPostIt=0;

	    for(i=0;i<N_USUARIOS;i++)
            hf_sempost(&enchendo); // up
        
		hf_sempost(&mutex);

	}
}

void app_main(void){
	int32_t i;

	hf_seminit(&cheia, 0);
	hf_seminit(&mutex, 1);
	hf_seminit(&enchendo, N_USUARIOS);

	for(i = 0; i < N_USUARIOS; i++)
		hf_spawn(usuario, 0, 0, 0, "usuario", 2048);

	hf_spawn(pombo, 0, 0, 0, "pombo", 2048);

}

