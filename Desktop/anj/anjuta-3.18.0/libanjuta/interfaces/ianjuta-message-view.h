/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-message-view.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_MESSAGE_VIEW_H_
#define _IANJUTA_MESSAGE_VIEW_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_MESSAGE_VIEW (ianjuta_message_view_get_type ())
#define IANJUTA_MESSAGE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_MESSAGE_VIEW, IAnjutaMessageView))
#define IANJUTA_IS_MESSAGE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_MESSAGE_VIEW))
#define IANJUTA_MESSAGE_VIEW_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_MESSAGE_VIEW, IAnjutaMessageViewIface))

#define IANJUTA_TYPE_MESSAGE_VIEW_TYPE (ianjuta_message_view_type_get_type())

#define IANJUTA_MESSAGE_VIEW_ERROR ianjuta_message_view_error_quark()

typedef struct _IAnjutaMessageView IAnjutaMessageView;
typedef struct _IAnjutaMessageViewIface IAnjutaMessageViewIface;

  /**
   * IAnjutaMessageViewType:
   * @IANJUTA_MESSAGE_VIEW_TYPE_NORMAL: Normal message
   * @IANJUTA_MESSAGE_VIEW_TYPE_INFO: Info message (highlighed)
   * @IANJUTA_MESSAGE_VIEW_TYPE_ERROR: Error message
   * @IANJUTA_MESSAGE_VIEW_TYPE_WARNING: Warning message
   *
   * Speficy the type ot the message added to the message view
   */
typedef enum {
	IANJUTA_MESSAGE_VIEW_TYPE_NORMAL,
	IANJUTA_MESSAGE_VIEW_TYPE_INFO,
	IANJUTA_MESSAGE_VIEW_TYPE_WARNING,
	IANJUTA_MESSAGE_VIEW_TYPE_ERROR
} IAnjutaMessageViewType;


struct _IAnjutaMessageViewIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*buffer_flushed) (IAnjutaMessageView *obj, const gchar *line);
	/* Signal */
	void (*message_clicked) (IAnjutaMessageView *obj, const gchar *message);

	void (*append) (IAnjutaMessageView *obj, IAnjutaMessageViewType type,  const gchar *summary,  const gchar *details, GError **err);
	void (*buffer_append) (IAnjutaMessageView *obj, const gchar *text, GError **err);
	void (*clear) (IAnjutaMessageView *obj, GError **err);
	GList* (*get_all_messages) (IAnjutaMessageView *obj, GError **err);
	const gchar* (*get_current_message) (IAnjutaMessageView *obj, GError **err);
	void (*select_next) (IAnjutaMessageView *obj, GError **err);
	void (*select_previous) (IAnjutaMessageView *obj, GError **err);

};

GType ianjuta_message_view_type_get_type (void);

GQuark ianjuta_message_view_error_quark     (void);
GType  ianjuta_message_view_get_type        (void);

void ianjuta_message_view_append (IAnjutaMessageView *obj, IAnjutaMessageViewType type,  const gchar *summary,  const gchar *details, GError **err);

void ianjuta_message_view_buffer_append (IAnjutaMessageView *obj, const gchar *text, GError **err);

void ianjuta_message_view_clear (IAnjutaMessageView *obj, GError **err);

GList* ianjuta_message_view_get_all_messages (IAnjutaMessageView *obj, GError **err);

const gchar* ianjuta_message_view_get_current_message (IAnjutaMessageView *obj, GError **err);

void ianjuta_message_view_select_next (IAnjutaMessageView *obj, GError **err);

void ianjuta_message_view_select_previous (IAnjutaMessageView *obj, GError **err);


G_END_DECLS

#endif
