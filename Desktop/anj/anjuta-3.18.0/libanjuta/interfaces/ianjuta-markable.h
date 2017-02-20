/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-markable.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_MARKABLE_H_
#define _IANJUTA_MARKABLE_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_MARKABLE (ianjuta_markable_get_type ())
#define IANJUTA_MARKABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_MARKABLE, IAnjutaMarkable))
#define IANJUTA_IS_MARKABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_MARKABLE))
#define IANJUTA_MARKABLE_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_MARKABLE, IAnjutaMarkableIface))

#define IANJUTA_TYPE_MARKABLE_ERROR (ianjuta_markable_error_get_type())
#define IANJUTA_TYPE_MARKABLE_MARKER (ianjuta_markable_marker_get_type())

#define IANJUTA_MARKABLE_ERROR ianjuta_markable_error_quark()

typedef struct _IAnjutaMarkable IAnjutaMarkable;
typedef struct _IAnjutaMarkableIface IAnjutaMarkableIface;

typedef enum {
	IANJUTA_MARKABLE_INVALID_LOCATION
} IAnjutaMarkableError;

  /**
   * IAnjutaMarkableMarker:
   * @IANJUTA_MARKABLE_LINEMARKER: Mark a particular line
   * @IANJUTA_MARKABLE_BOOKMARK: A bookmark
   * @IANJUTA_MARKABLE_MESSAGE: An (error) message
   * @IANJUTA_MARKABLE_BREAKPOINT_DISABLED: a disabled breakpoint
   * @IANJUTA_MARKABLE_BREAKPOINT_ENABLED: a enabled breakpoint
   * @IANJUTA_MARKABLE_PROGRAM_COUNTER: Marks the program counter position
   *
   * This enumeration is used to specify the pixmap used for the marker
   */
typedef enum {
	IANJUTA_MARKABLE_LINEMARKER,
	IANJUTA_MARKABLE_BOOKMARK,
	IANJUTA_MARKABLE_MESSAGE,
	IANJUTA_MARKABLE_BREAKPOINT_DISABLED,
	IANJUTA_MARKABLE_BREAKPOINT_ENABLED,
	IANJUTA_MARKABLE_PROGRAM_COUNTER
} IAnjutaMarkableMarker;


struct _IAnjutaMarkableIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*marker_clicked) (IAnjutaMarkable *obj, gboolean double_click,  gint location);

	void (*delete_all_markers) (IAnjutaMarkable *obj, IAnjutaMarkableMarker marker, GError **err);
	gboolean (*is_marker_set) (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker, GError **err);
	gint (*location_from_handle) (IAnjutaMarkable *obj, gint handle, GError **err);
	gint (*mark) (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker,  const gchar* tooltip, GError **err);
	void (*unmark) (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker, GError **err);

};

GType ianjuta_markable_error_get_type (void);
GType ianjuta_markable_marker_get_type (void);

GQuark ianjuta_markable_error_quark     (void);
GType  ianjuta_markable_get_type        (void);

void ianjuta_markable_delete_all_markers (IAnjutaMarkable *obj, IAnjutaMarkableMarker marker, GError **err);

gboolean ianjuta_markable_is_marker_set (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker, GError **err);

gint ianjuta_markable_location_from_handle (IAnjutaMarkable *obj, gint handle, GError **err);

gint ianjuta_markable_mark (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker,  const gchar* tooltip, GError **err);

void ianjuta_markable_unmark (IAnjutaMarkable *obj, gint location,  IAnjutaMarkableMarker marker, GError **err);


G_END_DECLS

#endif
