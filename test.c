/*************************************************************************************************/
/*                 HYREC: Hydrogen and Helium Recombination Code                                 */
/*         Written by Yacine Ali-Haimoud and Chris Hirata (Caltech)                              */
/*                                                                                               */
/*         hydrogen.c: all functions related to Hydrogen recombination                           */
/*                                                                                               */
/*         Units used: cgs + eV (all temperatures in eV)                                         */
/*                                                                                               */
/*         Version: May 2012                                                                     */ 
/*                                                                                               */
/*         Revision history:                                                                     */
/*            - Written November 2010                                                            */
/*            - January 2011: - changed the post-Saha expansion to use the full derivative       */
/*                       (including two-photon processes and diffusion) rather than Peebles'ODE  */
/*	                      - post-Saha expansion can now pass the difference from Saha value  */
/*                                  to external routines                                         */              
/*                            - differential 2s--1s rate is now systematically normalized to     */
/*                                 total 2s--1s rate that can be set by user in hydrogen.h       */
/*            - May 2012: - Now solve for the photon distortion instead of absolute value        */
/*                               of radiation field (less prone to numerical errors)             */
/*                          - Improved the post-Saha expansion to properly account for           */
/*                               non-thermal distortions                                         */
/*                          - Added explicit dependence on fine-structure constant               */
/*                           (fsR = alpha/alpha0) and electron mass (meR = me/me0 ~ mue/mue0)    */
/*                          - Included dependence on xe and xHII in case HeII still present      */
/*************************************************************************************************/ 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double *create_1D_array(unsigned n1);

int main(void) {
  double *rs = create_1D_array(844);
  double *fz = create_1D_array(844);
  FILE *fz_table = fopen("fz_ee_100MeV_recfast.dat", "r");
  printf("Everything is okay \n");
  int i;
  for (i=0; i < 20; ++i) {
    fscanf(fz_table,"%lf,%lf",&rs[i],&fz[i]);
    printf("rs is %lf and fz is %lf \n",rs[i],fz[i]);
    }
  // fscanf(fz_table,"%lf,%lf",rs,fz);
  // printf("fz is %f",*rs[0]);
  fclose(fz_table);
return(0);
}

double *create_1D_array(unsigned n1){

   double *matrix = (double *) calloc(n1, sizeof(double));
   if (matrix == NULL) {
      fprintf(stderr, "Error in create_1D_array: unable to allocate memory\n");
      exit(1);
    }
   return matrix;
}