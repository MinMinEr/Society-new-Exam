/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * anjuta
 * Copyright (C) James Liggett 2008 <jrliggett@cox.net>
 * 
 * anjuta is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * anjuta is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with anjuta.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#ifndef _GIT_INIT_COMMAND_H_
#define _GIT_INIT_COMMAND_H_

#include <glib-object.h>
#include "git-command.h"

G_BEGIN_DECLS

#define GIT_TYPE_INIT_COMMAND             (git_init_command_get_type ())
#define GIT_INIT_COMMAND(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIT_TYPE_INIT_COMMAND, GitInitCommand))
#define GIT_INIT_COMMAND_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GIT_TYPE_INIT_COMMAND, GitInitCommandClass))
#define GIT_IS_INIT_COMMAND(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIT_TYPE_INIT_COMMAND))
#define GIT_IS_INIT_COMMAND_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GIT_TYPE_INIT_COMMAND))
#define GIT_INIT_COMMAND_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GIT_TYPE_INIT_COMMAND, GitInitCommandClass))

typedef struct _GitInitCommandClass GitInitCommandClass;
typedef struct _GitInitCommand GitInitCommand;

struct _GitInitCommandClass
{
	GitCommandClass parent_class;
};

struct _GitInitCommand
{
	GitCommand parent_instance;
};

GType git_init_command_get_type (void) G_GNUC_CONST;
GitInitCommand *git_init_command_new (const gchar *working_directory);

G_END_DECLS

#endif /* _GIT_INIT_COMMAND_H_ */
