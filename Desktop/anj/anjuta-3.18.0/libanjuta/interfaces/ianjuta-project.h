/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-project.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_PROJECT_H_
#define _IANJUTA_PROJECT_H_

#include <glib-object.h>
#include <libanjuta/anjuta-project.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_PROJECT (ianjuta_project_get_type ())
#define IANJUTA_PROJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_PROJECT, IAnjutaProject))
#define IANJUTA_IS_PROJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_PROJECT))
#define IANJUTA_PROJECT_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_PROJECT, IAnjutaProjectIface))

#define IANJUTA_TYPE_PROJECT_ERROR (ianjuta_project_error_get_type())
#define IANJUTA_TYPE_PROJECT_PROBE (ianjuta_project_probe_get_type())

#define IANJUTA_PROJECT_ERROR ianjuta_project_error_quark()

typedef struct _IAnjutaProject IAnjutaProject;
typedef struct _IAnjutaProjectIface IAnjutaProjectIface;

/* Types */
typedef enum {
	IANJUTA_PROJECT_ERROR_SUCCESS = 0,
	IANJUTA_PROJECT_ERROR_DOESNT_EXIST,
	IANJUTA_PROJECT_ERROR_ALREADY_EXISTS,
	IANJUTA_PROJECT_ERROR_VALIDATION_FAILED,
	IANJUTA_PROJECT_ERROR_PROJECT_MALFORMED,
	IANJUTA_PROJECT_ERROR_WRONG_PARENT,
	IANJUTA_PROJECT_ERROR_NOT_SUPPORTED,
	IANJUTA_PROJECT_ERROR_GENERAL_FAILURE
} IAnjutaProjectError;

typedef enum {
	IANJUTA_PROJECT_PROBE_FILES = 10,
	IANJUTA_PROJECT_PROBE_MAKE_FILES = 100,
	IANJUTA_PROJECT_PROBE_PROJECT_FILES = 200
} IAnjutaProjectProbe;


struct _IAnjutaProjectIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*file_changed) (IAnjutaProject *obj, gpointer node);
	/* Signal */
	void (*node_changed) (IAnjutaProject *obj, gpointer node,  GError *error);
	/* Signal */
	void (*node_loaded) (IAnjutaProject *obj, gpointer node,  GError *error);
	/* Signal */
	void (*node_saved) (IAnjutaProject *obj, gpointer node,  GError *error);

	AnjutaProjectNode * (*add_node_after) (IAnjutaProject *obj, AnjutaProjectNode *parent,  AnjutaProjectNode *sibling,  AnjutaProjectNodeType type,  GFile *file,  const gchar *name, GError **err);
	AnjutaProjectNode * (*add_node_before) (IAnjutaProject *obj, AnjutaProjectNode *parent,  AnjutaProjectNode *sibling,  AnjutaProjectNodeType type,  GFile *file,  const gchar *name, GError **err);
	const GList* (*get_node_info) (IAnjutaProject *obj, GError **err);
	AnjutaProjectNode * (*get_root) (IAnjutaProject *obj, GError **err);
	gboolean (*is_loaded) (IAnjutaProject *obj, GError **err);
	gboolean (*load_node) (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);
	gboolean (*remove_node) (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);
	gboolean (*remove_property) (IAnjutaProject *obj, AnjutaProjectNode *node,  const gchar *id,  const gchar *name, GError **err);
	gboolean (*save_node) (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);
	AnjutaProjectProperty * (*set_property) (IAnjutaProject *obj, AnjutaProjectNode *node,  const gchar *id,  const gchar *name,  const gchar *value, GError **err);

};

GType ianjuta_project_error_get_type (void);
GType ianjuta_project_probe_get_type (void);

GQuark ianjuta_project_error_quark     (void);
GType  ianjuta_project_get_type        (void);

AnjutaProjectNode * ianjuta_project_add_node_after (IAnjutaProject *obj, AnjutaProjectNode *parent,  AnjutaProjectNode *sibling,  AnjutaProjectNodeType type,  GFile *file,  const gchar *name, GError **err);

AnjutaProjectNode * ianjuta_project_add_node_before (IAnjutaProject *obj, AnjutaProjectNode *parent,  AnjutaProjectNode *sibling,  AnjutaProjectNodeType type,  GFile *file,  const gchar *name, GError **err);

const GList* ianjuta_project_get_node_info (IAnjutaProject *obj, GError **err);

AnjutaProjectNode * ianjuta_project_get_root (IAnjutaProject *obj, GError **err);

gboolean ianjuta_project_is_loaded (IAnjutaProject *obj, GError **err);

gboolean ianjuta_project_load_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);

gboolean ianjuta_project_remove_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);

gboolean ianjuta_project_remove_property (IAnjutaProject *obj, AnjutaProjectNode *node,  const gchar *id,  const gchar *name, GError **err);

gboolean ianjuta_project_save_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err);

AnjutaProjectProperty * ianjuta_project_set_property (IAnjutaProject *obj, AnjutaProjectNode *node,  const gchar *id,  const gchar *name,  const gchar *value, GError **err);


G_END_DECLS

#endif