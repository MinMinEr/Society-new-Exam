/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * anjuta
 * Copyright (C) Johannes Schmid 2012 <jhs@gnome.org>
 * 
 * anjuta is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * anjuta is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SEARCH_FILE_COMMAND_H_
#define _SEARCH_FILE_COMMAND_H_

#include <libanjuta/anjuta-async-command.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define SEARCH_TYPE_FILE_COMMAND             (search_file_command_get_type ())
#define SEARCH_FILE_COMMAND(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEARCH_TYPE_FILE_COMMAND, SearchFileCommand))
#define SEARCH_FILE_COMMAND_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), SEARCH_TYPE_FILE_COMMAND, SearchFileCommandClass))
#define SEARCH_IS_FILE_COMMAND(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEARCH_TYPE_FILE_COMMAND))
#define SEARCH_IS_FILE_COMMAND_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), SEARCH_TYPE_FILE_COMMAND))
#define SEARCH_FILE_COMMAND_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), SEARCH_TYPE_FILE_COMMAND, SearchFileCommandClass))

typedef struct _SearchFileCommandClass SearchFileCommandClass;
typedef struct _SearchFileCommand SearchFileCommand;
typedef struct _SearchFileCommandPrivate SearchFileCommandPrivate;

struct _SearchFileCommandClass
{
	AnjutaAsyncCommandClass parent_class;
};

struct _SearchFileCommand
{
	AnjutaAsyncCommand parent_instance;

	SearchFileCommandPrivate* priv;
};

GType search_file_command_get_type (void) G_GNUC_CONST;
SearchFileCommand* search_file_command_new (GFile* file, 
                                            const gchar* pattern, 
                                            const gchar* replace,
                                            gboolean case_sensitive,
                                            gboolean regex);
gint search_file_command_get_n_matches (SearchFileCommand* cmd);

G_END_DECLS

#endif /* _SEARCH_FILE_COMMAND_H_ */
