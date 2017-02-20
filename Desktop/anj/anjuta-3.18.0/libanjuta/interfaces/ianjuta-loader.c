/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-loader.c -- Autogenerated from libanjuta.idl
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

/**
 * SECTION:ianjuta-loader
 * @title: IAnjutaLoader
 * @short_description: Interface to load file or stream
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-loader.h
 *
 * Loaders can deterime correct plugin to open a file or stream.  They
 * themselves can not load it, but will correctly redirect the request to
 * an implementor of IAnjutaFile, IAnjutaFileSavable, IAnjutaStream or
 * IAnjutaStreamSavable, depending on the mime-type, meta-type or any other
 * requirements.
 */

#include "ianjuta-loader.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_loader_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-loader-quark");
	}
	
	return quark;
}

/**
 * ianjuta_loader_find_plugins:
 * @obj: Self
 * @err: Error propagation and reporting.
 *
 * Returns: (element-type AnjutaPlugin): all plugins supporting loader interface.
 */
GList*
ianjuta_loader_find_plugins (IAnjutaLoader *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_LOADER(obj), 0);
	return IANJUTA_LOADER_GET_IFACE (obj)->find_plugins (obj, err);
}

/* Default implementation */
static GList*
ianjuta_loader_find_plugins_default (IAnjutaLoader *obj, GError **err)
{
	g_return_val_if_reached (NULL);
}

static void
ianjuta_loader_base_init (IAnjutaLoaderIface* klass)
{
	static gboolean initialized = FALSE;

	klass->find_plugins = ianjuta_loader_find_plugins_default;
	
	if (!initialized) {

		initialized = TRUE;
	}
}

GType
ianjuta_loader_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaLoaderIface),
			(GBaseInitFunc) ianjuta_loader_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaLoader", &info, 0);
		g_type_interface_add_prerequisite (type, G_TYPE_OBJECT);
	}
	return type;			
}
