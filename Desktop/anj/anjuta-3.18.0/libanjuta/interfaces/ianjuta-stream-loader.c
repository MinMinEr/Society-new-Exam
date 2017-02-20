/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-stream-loader.c -- Autogenerated from libanjuta.idl
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
 * SECTION:ianjuta-stream-loader
 * @title: IAnjutaStreamLoader
 * @short_description: Loader to load streams
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-stream-loader.h
 *
 * StreamLoaders can deterime correct plugin to open a stream.
 */

#include "ianjuta-stream-loader.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_stream_loader_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-stream-loader-quark");
	}
	
	return quark;
}

/**
 * ianjuta_stream_loader_load:
 * @obj: Self
 * @stream: Stream to load
 * @readonly: Open in readonly mode.
 * @err: Error propagation and reporting
 *
 * Determines a plugin which can open the given stream, activates it
 * opening the stream and returns the interface of the plugin activated.
 *
 * Return value: Plugin interface used to load the stream.
 */
GObject*
ianjuta_stream_loader_load (IAnjutaStreamLoader *obj, FILE *stream,   gboolean readonly, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_STREAM_LOADER(obj), NULL);
	return IANJUTA_STREAM_LOADER_GET_IFACE (obj)->load (obj, stream, readonly, err);
}

/* Default implementation */
static GObject*
ianjuta_stream_loader_load_default (IAnjutaStreamLoader *obj, FILE *stream,   gboolean readonly, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_stream_loader_peek_interface:
 * @obj: Self
 * @stream: Stream to load
 * @err: Error propagation and reporting
 *
 * Peeks the stream and determines the interface which can load
 * this stream.
 *
 * Return value: Plugin interface name that can load the stream.
 */
gchar*
ianjuta_stream_loader_peek_interface (IAnjutaStreamLoader *obj, FILE *stream, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_STREAM_LOADER(obj), NULL);
	return IANJUTA_STREAM_LOADER_GET_IFACE (obj)->peek_interface (obj, stream, err);
}

/* Default implementation */
static gchar*
ianjuta_stream_loader_peek_interface_default (IAnjutaStreamLoader *obj, FILE *stream, GError **err)
{
	g_return_val_if_reached (NULL);
}

static void
ianjuta_stream_loader_base_init (IAnjutaStreamLoaderIface* klass)
{
	static gboolean initialized = FALSE;

	klass->load = ianjuta_stream_loader_load_default;
	klass->peek_interface = ianjuta_stream_loader_peek_interface_default;
	
	if (!initialized) {

		initialized = TRUE;
	}
}

GType
ianjuta_stream_loader_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaStreamLoaderIface),
			(GBaseInitFunc) ianjuta_stream_loader_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaStreamLoader", &info, 0);
		g_type_interface_add_prerequisite (type, IANJUTA_TYPE_LOADER);
	}
	return type;			
}
