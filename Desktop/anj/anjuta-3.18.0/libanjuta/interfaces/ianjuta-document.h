/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-document.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_DOCUMENT_H_
#define _IANJUTA_DOCUMENT_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_DOCUMENT (ianjuta_document_get_type ())
#define IANJUTA_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_DOCUMENT, IAnjutaDocument))
#define IANJUTA_IS_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_DOCUMENT))
#define IANJUTA_DOCUMENT_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_DOCUMENT, IAnjutaDocumentIface))

#define IANJUTA_DOCUMENT_ERROR ianjuta_document_error_quark()

typedef struct _IAnjutaDocument IAnjutaDocument;
typedef struct _IAnjutaDocumentIface IAnjutaDocumentIface;


struct _IAnjutaDocumentIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*update_ui) (IAnjutaDocument *obj);

	void (*begin_undo_action) (IAnjutaDocument *obj, GError **err);
	gboolean (*can_redo) (IAnjutaDocument *obj, GError **err);
	gboolean (*can_undo) (IAnjutaDocument *obj, GError **err);
	void (*clear) (IAnjutaDocument *obj, GError **err);
	void (*copy) (IAnjutaDocument *obj, GError **err);
	void (*cut) (IAnjutaDocument *obj, GError **err);
	void (*end_undo_action) (IAnjutaDocument *obj, GError **err);
	const gchar* (*get_filename) (IAnjutaDocument *obj, GError **err);
	void (*grab_focus) (IAnjutaDocument *obj, GError **err);
	void (*paste) (IAnjutaDocument *obj, GError **err);
	void (*redo) (IAnjutaDocument *obj, GError **err);
	void (*undo) (IAnjutaDocument *obj, GError **err);

};


GQuark ianjuta_document_error_quark     (void);
GType  ianjuta_document_get_type        (void);

void ianjuta_document_begin_undo_action (IAnjutaDocument *obj, GError **err);

gboolean ianjuta_document_can_redo (IAnjutaDocument *obj, GError **err);

gboolean ianjuta_document_can_undo (IAnjutaDocument *obj, GError **err);

void ianjuta_document_clear (IAnjutaDocument *obj, GError **err);

void ianjuta_document_copy (IAnjutaDocument *obj, GError **err);

void ianjuta_document_cut (IAnjutaDocument *obj, GError **err);

void ianjuta_document_end_undo_action (IAnjutaDocument *obj, GError **err);

const gchar* ianjuta_document_get_filename (IAnjutaDocument *obj, GError **err);

void ianjuta_document_grab_focus (IAnjutaDocument *obj, GError **err);

void ianjuta_document_paste (IAnjutaDocument *obj, GError **err);

void ianjuta_document_redo (IAnjutaDocument *obj, GError **err);

void ianjuta_document_undo (IAnjutaDocument *obj, GError **err);


G_END_DECLS

#endif