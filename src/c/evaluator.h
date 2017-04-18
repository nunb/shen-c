#ifndef SHEN_C_EVALUATOR_H
#define SHEN_C_EVALUATOR_H

#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>

#include "character.h"
#include "environment.h"
#include "exception.h"
#include "function.h"
#include "kl.h"
#include "list.h"
#include "loop.h"
#include "object.h"
#include "number.h"
#include "reader.h"
#include "string.h"
#include "symbol.h"

KLObject* eval_kl_object (KLObject* object, Environment* function_environment,
                          Environment* variable_environment);

#endif
