/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-file-loader.h -- Autogenerated from libanjuta.idl
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _IANJUTA_FILE_LOADER_H_
#define _IANJUTA_FILE_LOADER_H_

#include <glib-object.h>
#include <gio/gio.h>
#include <libanjuta/interfaces/ianjuta-loader.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_FILE_LOADER (ianjuta_file_loader_get_type ())
#define IANJUTA_FILE_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_FILE_LOADER, IAnjutaFileLoader))
#define IANJUTA_IS_FILE_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_FILE_LOADER))
#define IANJUTA_FILE_LOADER_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_FILE_LOADER, IAnjutaFileLoaderIface))

#define IANJUTA_FILE_LOADER_ERROR ianjuta_file_loader_error_quark()

typedef struct _IAnjutaFileLoader IAnjutaFileLoader;
typedef struct _IAnjutaFileLoaderIface IAnjutaFileLoaderIface;


struct _IAnjutaFileLoaderIface {
	IAnjutaLoaderIface g_iface;
	

	GObject* (*load) (IAnjutaFileLoader *obj, GFile* file,  gboolean readonly, GError **err);
	gchar* (*peek_interface) (IAnjutaFileLoader *obj, GFile* file, GError **err);

};


GQuark ianjuta_file_loader_error_quark     (void);
GType  ianjuta_file_loader_get_type        (void);

GObject* ianjuta_file_loader_load (IAnjutaFileLoader *obj, GFile* file,  gboolean readonly, GError **err);

gchar* ianjuta_file_loader_peek_interface (IAnjutaFileLoader *obj, GFile* file, GError **err);


G_END_DECLS

#endif