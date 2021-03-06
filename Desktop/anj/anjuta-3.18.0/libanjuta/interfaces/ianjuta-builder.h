/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-builder.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_BUILDER_H_
#define _IANJUTA_BUILDER_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_BUILDER (ianjuta_builder_get_type ())
#define IANJUTA_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_BUILDER, IAnjutaBuilder))
#define IANJUTA_IS_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_BUILDER))
#define IANJUTA_BUILDER_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_BUILDER, IAnjutaBuilderIface))

#define IANJUTA_TYPE_BUILDER_ERROR (ianjuta_builder_error_get_type())

#define IANJUTA_BUILDER_ERROR ianjuta_builder_error_quark()

/**
* IANJUTA_BUILDER_ROOT_URI:
*
* Build directory uri. It is the same than the project_root_uri for
* in source build.
*/
#define	IANJUTA_BUILDER_ROOT_URI	"build_root_uri"

/**
* IANJUTA_BUILDER_CONFIGURATION_DEBUG:
*
* Name of debugging configutation.
*/
#define	IANJUTA_BUILDER_CONFIGURATION_DEBUG	"Debug"

/**
* IANJUTA_BUILDER_CONFIGURATION_OPTIMIZED:
*
* Name of optimized configutation.
*/
#define	IANJUTA_BUILDER_CONFIGURATION_OPTIMIZED	"Optimized"

/**
* IANJUTA_BUILDER_CONFIGURATION_PROFILING:
*
* Name of profiling configutation.
*/
#define	IANJUTA_BUILDER_CONFIGURATION_PROFILING	"Profiling"


typedef struct _IAnjutaBuilder IAnjutaBuilder;
typedef struct _IAnjutaBuilderIface IAnjutaBuilderIface;

  /**
   * IAnjutaBuilderError:
   * @IANJUTA_BUILDER_SUCCEED: Build succeeded
   * @IANJUTA_BUILDER_FAILED: Build failed
   * @IANJUTA_BUILDER_CANCELED: Build was canceld
   * @IANJUTA_BUILDER_ABORTED: Build aborted
   * @IANJUTA_BUILDER_INTERRUPTED: Build interruped
   * @IANJUTA_BUILDER_TERMINATED: Build interruped
   * @IANJUTA_BUILDER_UNKNOWN_TARGET: The specified target is unknown
   * @IANJUTA_BUILDER_UNKNOWN_ERROR: Unknown Error
   * @IANJUTA_BUILDER_OTHER_ERROR: Other Error (no unknown ;-))
   *
   * Possible build errors
   */
typedef enum {
	IANJUTA_BUILDER_SUCCEED           =  0,
	IANJUTA_BUILDER_FAILED,
	IANJUTA_BUILDER_CANCELED	= 256,
	IANJUTA_BUILDER_ABORTED,
	IANJUTA_BUILDER_INTERRUPTED,
	IANJUTA_BUILDER_TERMINATED,
	IANJUTA_BUILDER_UNKNOWN_TARGET,
	IANJUTA_BUILDER_UNKNOWN_ERROR,
	IANJUTA_BUILDER_OTHER_ERROR
} IAnjutaBuilderError;

typedef gpointer IAnjutaBuilderHandle;

typedef void (*IAnjutaBuilderCallback) (GObject *sender, IAnjutaBuilderHandle command, GError* err, gpointer user_data);



struct _IAnjutaBuilderIface {
	GTypeInterface g_iface;
	

	IAnjutaBuilderHandle (*build) (IAnjutaBuilder *obj, const gchar *uri,  IAnjutaBuilderCallback callback,  gpointer user_data, GError **err);
	void (*cancel) (IAnjutaBuilder *obj, IAnjutaBuilderHandle handle, GError **err);
	const gchar* (*get_uri_configuration) (IAnjutaBuilder *obj, const gchar *uri, GError **err);
	IAnjutaBuilderHandle (*is_built) (IAnjutaBuilder *obj, const gchar *uri,  IAnjutaBuilderCallback callback,  gpointer user_data, GError **err);
	GList* (*list_configuration) (IAnjutaBuilder *obj, GError **err);

};

GType ianjuta_builder_error_get_type (void);

GQuark ianjuta_builder_error_quark     (void);
GType  ianjuta_builder_get_type        (void);

IAnjutaBuilderHandle ianjuta_builder_build (IAnjutaBuilder *obj, const gchar *uri,  IAnjutaBuilderCallback callback,  gpointer user_data, GError **err);

void ianjuta_builder_cancel (IAnjutaBuilder *obj, IAnjutaBuilderHandle handle, GError **err);

const gchar* ianjuta_builder_get_uri_configuration (IAnjutaBuilder *obj, const gchar *uri, GError **err);

IAnjutaBuilderHandle ianjuta_builder_is_built (IAnjutaBuilder *obj, const gchar *uri,  IAnjutaBuilderCallback callback,  gpointer user_data, GError **err);

GList* ianjuta_builder_list_configuration (IAnjutaBuilder *obj, GError **err);


G_END_DECLS

#endif
