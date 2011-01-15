/*-------------------------------------------------------------------------
 *
 * copy.h
 *	  Definitions for using the POSTGRES copy command.
 *
 *
 * Portions Copyright (c) 1996-2011, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/commands/copy.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef COPY_H
#define COPY_H

#include "nodes/execnodes.h"
#include "nodes/parsenodes.h"
#include "tcop/dest.h"


typedef struct CopyStateData  *CopyState;

extern uint64 DoCopy(const CopyStmt *stmt, const char *queryString);

extern CopyState BeginCopyFrom(Relation rel, const char *filename,
							   List *attnamelist, List *options);
extern void EndCopyFrom(CopyState cstate);
extern HeapTuple NextCopyFrom(CopyState cstate);
extern void CopyFromErrorCallback(void *arg);

extern DestReceiver *CreateCopyDestReceiver(void);

#endif   /* COPY_H */
