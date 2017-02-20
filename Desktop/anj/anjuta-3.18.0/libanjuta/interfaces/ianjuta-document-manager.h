/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-document-manager.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_DOCUMENT_MANAGER_H_
#define _IANJUTA_DOCUMENT_MANAGER_H_

#include <glib-object.h>
#include <libanjuta/interfaces/ianjuta-document.h>
#include <libanjuta/interfaces/ianjuta-editor.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_DOCUMENT_MANAGER (ianjuta_document_manager_get_type ())
#define IANJUTA_DOCUMENT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_DOCUMENT_MANAGER, IAnjutaDocumentManager))
#define IANJUTA_IS_DOCUMENT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_DOCUMENT_MANAGER))
#define IANJUTA_DOCUMENT_MANAGER_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_DOCUMENT_MANAGER, IAnjutaDocumentManagerIface))

#define IANJUTA_TYPE_DOCUMENT_MANAGER_ERROR (ianjuta_document_manager_error_get_type())

#define IANJUTA_DOCUMENT_MANAGER_ERROR ianjuta_document_manager_error_quark()

/**
* IANJUTA_DOCUMENT_MANAGER_CURRENT_DOCUMENT:
*
* Anjuta shell value set by document manager to the current document
*/
#define	IANJUTA_DOCUMENT_MANAGER_CURRENT_DOCUMENT	"document_manager_current_document"


typedef struct _IAnjutaDocumentManager IAnjutaDocumentManager;
typedef struct _IAnjutaDocumentManagerIface IAnjutaDocumentManagerIface;

typedef enum {
	IANJUTA_DOCUMENT_MANAGER_DOESNT_EXIST
} IAnjutaDocumentManagerError;


struct _IAnjutaDocumentManagerIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*document_added) (IAnjutaDocumentManager *obj, IAnjutaDocument* doc);
	/* Signal */
	void (*document_removed) (IAnjutaDocumentManager *obj, IAnjutaDocument* doc);

	void (*add_bookmark) (IAnjutaDocumentManager *obj, GFile* file,  gint line, GError **err);
	IAnjutaEditor* (*add_buffer) (IAnjutaDocumentManager *obj, const gchar *name,  const gchar* content, GError **err);
	void (*add_document) (IAnjutaDocumentManager *obj, IAnjutaDocument* document, GError **err);
	IAnjutaDocument* (*find_document_with_file) (IAnjutaDocumentManager *obj, GFile* file, GError **err);
	IAnjutaDocument* (*get_current_document) (IAnjutaDocumentManager *obj, GError **err);
	GList* (*get_doc_widgets) (IAnjutaDocumentManager *obj, GError **err);
	GFile* (*get_file) (IAnjutaDocumentManager *obj, const gchar *filename, GError **err);
	IAnjutaEditor* (*goto_file_line) (IAnjutaDocumentManager *obj, GFile* file,  gint lineno, GError **err);
	IAnjutaEditor* (*goto_file_line_mark) (IAnjutaDocumentManager *obj, GFile* file,  gint lineno,  gboolean mark, GError **err);
	gboolean (*remove_document) (IAnjutaDocumentManager *obj, IAnjutaDocument *document,  gboolean save_before, GError **err);
	void (*set_current_document) (IAnjutaDocumentManager *obj, IAnjutaDocument *document, GError **err);

};

GType ianjuta_document_manager_error_get_type (void);

GQuark ianjuta_document_manager_error_quark     (void);
GType  ianjuta_document_manager_get_type        (void);

void ianjuta_document_manager_add_bookmark (IAnjutaDocumentManager *obj, GFile* file,  gint line, GError **err);

IAnjutaEditor* ianjuta_document_manager_add_buffer (IAnjutaDocumentManager *obj, const gchar *name,  const gchar* content, GError **err);

void ianjuta_document_manager_add_document (IAnjutaDocumentManager *obj, IAnjutaDocument* document, GError **err);

IAnjutaDocument* ianjuta_document_manager_find_document_with_file (IAnjutaDocumentManager *obj, GFile* file, GError **err);

IAnjutaDocument* ianjuta_document_manager_get_current_document (IAnjutaDocumentManager *obj, GError **err);

GList* ianjuta_document_manager_get_doc_widgets (IAnjutaDocumentManager *obj, GError **err);

GFile* ianjuta_document_manager_get_file (IAnjutaDocumentManager *obj, const gchar *filename, GError **err);

IAnjutaEditor* ianjuta_document_manager_goto_file_line (IAnjutaDocumentManager *obj, GFile* file,  gint lineno, GError **err);

IAnjutaEditor* ianjuta_document_manager_goto_file_line_mark (IAnjutaDocumentManager *obj, GFile* file,  gint lineno,  gboolean mark, GError **err);

gboolean ianjuta_document_manager_remove_document (IAnjutaDocumentManager *obj, IAnjutaDocument *document,  gboolean save_before, GError **err);

void ianjuta_document_manager_set_current_document (IAnjutaDocumentManager *obj, IAnjutaDocument *document, GError **err);


G_END_DECLS

#endif
