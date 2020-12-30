
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* This function is a PI controller model */
void FB_Regulator(struct FB_Regulator* inst)
{
	inst->integrator.in = inst->e*inst->k_i*inst->dt + inst->iyOld;
	FB_Integrator(&(inst->integrator));
	
	inst->e_p = inst->e*inst->k_p;
	
	if(inst->e_p < inst->max_abs_value || inst->e_p > -inst->max_abs_value);
	else
	{
		if(inst->e_p > 0) inst->e_p = inst->max_abs_value;
		else inst->e_p = -inst->max_abs_value;
	}
	
	inst->e_p += inst->integrator.out;
	if(inst->e_p < inst->max_abs_value || inst->e_p > -inst->max_abs_value)
		inst->u = inst->e_p;
	else
	{
		if(inst->e_p > 0) inst->u = inst->max_abs_value;
		else inst->u = -inst->max_abs_value;
	}
	inst->iyOld = inst->u - inst->e_p;

}
