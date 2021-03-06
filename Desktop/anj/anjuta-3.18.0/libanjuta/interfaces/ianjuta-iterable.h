/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-iterable.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_ITERABLE_H_
#define _IANJUTA_ITERABLE_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_ITERABLE (ianjuta_iterable_get_type ())
#define IANJUTA_ITERABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_ITERABLE, IAnjutaIterable))
#define IANJUTA_IS_ITERABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_ITERABLE))
#define IANJUTA_ITERABLE_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_ITERABLE, IAnjutaIterableIface))

#define IANJUTA_ITERABLE_ERROR ianjuta_iterable_error_quark()

typedef struct _IAnjutaIterable IAnjutaIterable;
typedef struct _IAnjutaIterableIface IAnjutaIterableIface;


struct _IAnjutaIterableIface {
	GTypeInterface g_iface;
	

	void (*assign) (IAnjutaIterable *obj, IAnjutaIterable *src_iter, GError **err);
	IAnjutaIterable * (*clone) (IAnjutaIterable *obj, GError **err);
	gint (*compare) (IAnjutaIterable *obj, IAnjutaIterable *iter2, GError **err);
	gint (*diff) (IAnjutaIterable *obj, IAnjutaIterable *iter2, GError **err);
	gboolean (*first) (IAnjutaIterable *obj, GError **err);
	void (*foreach) (IAnjutaIterable *obj, GFunc callback,  gpointer user_data, GError **err);
	gint (*get_length) (IAnjutaIterable *obj, GError **err);
	gint (*get_position) (IAnjutaIterable *obj, GError **err);
	gboolean (*last) (IAnjutaIterable *obj, GError **err);
	gboolean (*next) (IAnjutaIterable *obj, GError **err);
	gboolean (*previous) (IAnjutaIterable *obj, GError **err);
	gboolean (*set_position) (IAnjutaIterable *obj, gint position, GError **err);

};


GQuark ianjuta_iterable_error_quark     (void);
GType  ianjuta_iterable_get_type        (void);

void ianjuta_iterable_assign (IAnjutaIterable *obj, IAnjutaIterable *src_iter, GError **err);

IAnjutaIterable * ianjuta_iterable_clone (IAnjutaIterable *obj, GError **err);

gint ianjuta_iterable_compare (IAnjutaIterable *obj, IAnjutaIterable *iter2, GError **err);

gint ianjuta_iterable_diff (IAnjutaIterable *obj, IAnjutaIterable *iter2, GError **err);

gboolean ianjuta_iterable_first (IAnjutaIterable *obj, GError **err);

void ianjuta_iterable_foreach (IAnjutaIterable *obj, GFunc callback,  gpointer user_data, GError **err);

gint ianjuta_iterable_get_length (IAnjutaIterable *obj, GError **err);

gint ianjuta_iterable_get_position (IAnjutaIterable *obj, GError **err);

gboolean ianjuta_iterable_last (IAnjutaIterable *obj, GError **err);

gboolean ianjuta_iterable_next (IAnjutaIterable *obj, GError **err);

gboolean ianjuta_iterable_previous (IAnjutaIterable *obj, GError **err);

gboolean ianjuta_iterable_set_position (IAnjutaIterable *obj, gint position, GError **err);


G_END_DECLS

#endif
