/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */


/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */
#define TAILLE_MAX_COMPRESS 10
#define DELAY_UART 50
#define MAX_ARRAY 256

	uint8_t texteCompress[TAILLE_MAX_COMPRESS];
	uint32_t tabCaractere[256]={0}; //tableau
	uint32_t nbrCaractereTotal =0;
	struct noeud* arbreHuffman[256];

/* Private macro -------------------------------------------------------------*/

struct noeud { //structure créer pour chaque caractère

	uint8_t c;  // caractère initiale
	uint32_t occurence; //Nombre d'occurence
	uint32_t code;
	uint32_t TailleCode;
	struct noeud *gauche, *droite;
};

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

//Projet Huffman
void myPrintf(uint8_t *text);
void occurence ( uint8_t* chaine, uint32_t tab[256]);
void creerFeuille (struct noeud * arbre[256], uint32_t tab[256]);
void affichageUART_Occurence(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
void myPrintf(uint8_t *text){

uint8_t buffer[50];

 sprintf(buffer, text);
 HAL_UART_Transmit(&huart2 , buffer, strlen(buffer), 1000); //transmission sur UART 2
}

__io_putchar(int ch){

	HAL_UART_Transmit(&huart2, &ch, 1, 1000);
}


void occurence ( uint8_t* chaine, uint32_t tab[256]) {
	   uint8_t CodeASCII = 0;
	   uint8_t compteur =0 ;
	   uint8_t TailleChaine =0 ;


	   TailleChaine = strlen(chaine);    //  taille de la chaine

	    for (int i = 0 ; i < TailleChaine ; i++) { 	//parcourt le tab
	        compteur =0;
	    	CodeASCII = chaine[i];

	    	  for (int j = 0 ; j < TailleChaine ; j++){ //parcourt le tab

	    		  if(chaine[j] == CodeASCII)
	    		  {
	    			  compteur++;
	    		  }
				}
	    	  tab[CodeASCII]= compteur;
	    		    }
}

void affichageUART_Occurence(void){
	//printf ("|__________|______________|______________|\n\r"); //première ligne
	    printf ("|Index[]   |  Caractere   |  Ocuurence   |\n\r"); //affichage titre collone
		//_________ Affichage occurence _________________
		   for (int i = 0 ; i < MAX_ARRAY ; i++) // on parcourt le tab
			    {
			   if (tabCaractere[i] != 0) { //si caractère present: pour pas afficher ailleurs

			    	printf ("   [%d]  ", i); //j'affiche l'index
			    	printf ("  | "); // séparation collone
			    	printf ("     '%c'  ", i); //j'affiche le caractère correspondant
			    	printf ("   | "); // séparation collone
			        printf( "          %d", tabCaractere[i]);  //j'affiche la valeur d'occurence du caractère correspodnant
			        //HAL_Delay(DELAY_UART);
			        printf ("  |\n\r"); // séparation collone

			   }

			    }
		   printf ("|__________|______________|______________|\n\r");

}

void creerFeuille (struct noeud * arbre[256], uint32_t tab[256]){


	  // Caractère present: jvai créer une structure pour chaque char trouvé
	    for (int j = 0 ; j < MAX_ARRAY ; j++) { 	//parcourt tabCactere

		    	if (tabCaractere[j]>0) { //si caractère present

		    		struct noeud *nouveauNoeud; //création un pointeur de type noeud: carnet d'@
		    		nouveauNoeud = (struct noeud*) malloc(sizeof(struct noeud)); //j'aloue de la mémoire

		    			// On remplit la structure: l'arbreHuffman
		    		nouveauNoeud->c=j; //caractère initiale: c'est la valeur de j
		    		nouveauNoeud->occurence=tabCaractere[j]; //valeur tab = nbr occurence
		    		nouveauNoeud->code=0;
		    		nouveauNoeud->TailleCode=0;
		    		nouveauNoeud->droite=NULL;
		    		nouveauNoeud->gauche=NULL;

		    		        //On remplit ArbreHufman avec l'@ de NouveauNoeud

		    		arbreHuffman[0] = nouveauNoeud; // à l'index 0 on a l'@ de la structure noeud de 'a'
		    		j++;

				}

	    }

}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{


	uint32_t nbrCaractereDifferent = 0;



	int var=0;

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	uint8_t texte[]="aaaabbbccd"; //texte en entrée
	struct noeud* memoireAllouee = NULL; // On crée un pointeur sur struct

	occurence(texte, tabCaractere); //calcul du nombre d'occurence de caractères dans texte
	affichageUART_Occurence(); //affichage UART

	int e =0; //on commence à 0 --> attention a faire a lexterieiur de la boucle
	//test carnet d'adresse
	  // Caractère present: jvai créer une structure pour chaque char trouvé
	    for (int j = 0 ; j < MAX_ARRAY ; j++) { 	//parcourt tabCactere

		    	if (tabCaractere[j]>0) { //si caractère present

		    		struct noeud *nouveauNoeud; //création un pointeur de type noeud: carnet d'@
		    		nouveauNoeud = (struct noeud*) malloc(sizeof(struct noeud)); //j'aloue de la mémoire

		    			// On remplit la structure: l'arbreHuffman
		    		nouveauNoeud->c=j; //caractère initiale: c'est la valeur de j
		    		nouveauNoeud->occurence=tabCaractere[j]; //valeur tab = nbr occurence
		    		nouveauNoeud->code=0;
		    		nouveauNoeud->TailleCode=0;
		    		nouveauNoeud->droite=NULL;
		    		nouveauNoeud->gauche=NULL;

		    		        //On remplit ArbreHufman avec l'@ de NouveauNoeud

		    		arbreHuffman[e] = nouveauNoeud; // à l'index 0 on a l'@ de la structure noeud de 'a'
		    		e++;

				}

			    }
	    		//affichage tableau d'huffman: tableau de structures
        printf ("Tab d'Huffman \n\r"); //j'affiche l'index
	    //_________ Affichage Tableau de huffman _________________
	    		   for (int k = 0 ; k < 10 ; k++) // on parcourt le tab
	    			    {

	    			    	printf ("[%d] \n\r", k); //j'affiche l'index
	    			        printf( "%d\n\r", arbreHuffman[k]);  //j'affiche la valeur d'occurence du caractère correspodnant

	    			   }
	    		   printf (" case 0 [%c] \n\r", arbreHuffman[0]->c);
	    		   printf ("case 0: occ %d \n\r", arbreHuffman[0]->occurence);
	    		   printf ("case 1 [%c] \n\r", arbreHuffman[1]->c);//caractère initiale: c'est la valeur de j
	    		   printf ("case 1: occ %d \n\r", arbreHuffman[1]->occurence);
	    		   printf ("case 2 [%c] \n\r", arbreHuffman[2]->c);//caractère initiale: c'est la valeur de j
	    		   printf ("case 2: occ %d \n\r", arbreHuffman[2]->occurence);
	    		   printf ("case 3 [%c] \n\r", arbreHuffman[3]->c);//caractère initiale: c'est la valeur de j
	    		   printf ("case 3: occ %d \n\r", arbreHuffman[3]->occurence);
	    		   //nouveauNoeud->occurence=tabCaractere[j]; //valeur tab = nbr occurence

	    			   // }



  while (1)
  {


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
