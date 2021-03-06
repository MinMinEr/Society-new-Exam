/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-project.c -- Autogenerated from libanjuta.idl
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
 * SECTION:ianjuta-project
 * @title: IAnjutaProject
 * @short_description: Interface implemented by project backend
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-project-backend.h
 *
 * This is the new interface that is replacing Gnome Build.
 */

#include "ianjuta-project.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_project_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-project-quark");
	}
	
	return quark;
}

/**
 * ianjuta_project_add_node_after:
 * @obj: Self
 * @parent: (transfer none): Parent
 * @sibling: (allow-none) (transfer none): Sibling
 * @type: Node type
 * @file: (allow-none) (transfer none): Optional file object for the node
 * @name: (allow-none) (transfer none): Optional name for the node
 * @err: Error propagation and reporting
 *
 * Create a new node and insert it after sibling
 *
 * Return value: (transfer none): The new node, NULL if error
 */
AnjutaProjectNode *
ianjuta_project_add_node_after (IAnjutaProject *obj, AnjutaProjectNode *parent,   AnjutaProjectNode *sibling,   AnjutaProjectNodeType type,   GFile *file,   const gchar *name, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), NULL);
	g_return_val_if_fail ((parent == NULL) ||ANJUTA_IS_PROJECT_NODE(parent), NULL);
	g_return_val_if_fail ((sibling == NULL) ||ANJUTA_IS_PROJECT_NODE(sibling), NULL);
	return IANJUTA_PROJECT_GET_IFACE (obj)->add_node_after (obj, parent, sibling, type, file, name, err);
}

/* Default implementation */
static AnjutaProjectNode *
ianjuta_project_add_node_after_default (IAnjutaProject *obj, AnjutaProjectNode *parent,   AnjutaProjectNode *sibling,   AnjutaProjectNodeType type,   GFile *file,   const gchar *name, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_project_add_node_before:
 * @obj: Self
 * @parent: (transfer none): Parent
 * @sibling: (allow-none) (transfer none): Sibling
 * @type: Node type
 * @file: (allow-none) (transfer none): Optional file object for the node
 * @name: (allow-none) (transfer none): Optional name for the node
 * @err: Error propagation and reporting
 *
 * Create a new node and insert it before sibling
 *
 * Return value: (transfer none): The new node, NULL if error
 */
AnjutaProjectNode *
ianjuta_project_add_node_before (IAnjutaProject *obj, AnjutaProjectNode *parent,   AnjutaProjectNode *sibling,   AnjutaProjectNodeType type,   GFile *file,   const gchar *name, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), NULL);
	g_return_val_if_fail ((parent == NULL) ||ANJUTA_IS_PROJECT_NODE(parent), NULL);
	g_return_val_if_fail ((sibling == NULL) ||ANJUTA_IS_PROJECT_NODE(sibling), NULL);
	return IANJUTA_PROJECT_GET_IFACE (obj)->add_node_before (obj, parent, sibling, type, file, name, err);
}

/* Default implementation */
static AnjutaProjectNode *
ianjuta_project_add_node_before_default (IAnjutaProject *obj, AnjutaProjectNode *parent,   AnjutaProjectNode *sibling,   AnjutaProjectNodeType type,   GFile *file,   const gchar *name, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_project_get_node_info:
 * @obj: Self
 * @err: Error propagation and reporting
 *
 * Return a list of possible node;
 *
 * Return value: (element-type Anjuta.ProjectNodeInfo) (transfer none): A list
 * containing information on all node supported by the project.
 */
const GList*
ianjuta_project_get_node_info (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), 0);
	return IANJUTA_PROJECT_GET_IFACE (obj)->get_node_info (obj, err);
}

/* Default implementation */
static const GList*
ianjuta_project_get_node_info_default (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_project_get_root:
 * @obj: Self
 * @err: Error propagation and reporting
 *
 * Get root_node
 *
 * Return value: (transfer none): The root node
 */
AnjutaProjectNode *
ianjuta_project_get_root (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), NULL);
	return IANJUTA_PROJECT_GET_IFACE (obj)->get_root (obj, err);
}

/* Default implementation */
static AnjutaProjectNode *
ianjuta_project_get_root_default (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_project_is_loaded:
 * @obj: Self
 * @err: Error propagation and reporting
 *
 * Return TRUE if the project is loaded;
 *
 * Return value: TRUE if the project is completely loaded.
 */
gboolean
ianjuta_project_is_loaded (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), FALSE);
	return IANJUTA_PROJECT_GET_IFACE (obj)->is_loaded (obj, err);
}

/* Default implementation */
static gboolean
ianjuta_project_is_loaded_default (IAnjutaProject *obj, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
 * ianjuta_project_load_node:
 * @obj: Self
 * @node: (transfer none): Project node to reload
 * @err: Error propagation and reporting
 *
 * Reload a project node
 *
 * Return value: TRUE if the node has been loaded without error
 */
gboolean
ianjuta_project_load_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), FALSE);
	g_return_val_if_fail ((node == NULL) ||ANJUTA_IS_PROJECT_NODE(node), FALSE);
	return IANJUTA_PROJECT_GET_IFACE (obj)->load_node (obj, node, err);
}

/* Default implementation */
static gboolean
ianjuta_project_load_node_default (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
 * ianjuta_project_remove_node:
 * @obj: Self
 * @node: (transfer none): Node
 * @err: Error propagation and reporting
 *
 * Remove a node
 *
 * Return value: TRUE if the node can be removed
 */
gboolean
ianjuta_project_remove_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), FALSE);
	g_return_val_if_fail ((node == NULL) ||ANJUTA_IS_PROJECT_NODE(node), FALSE);
	return IANJUTA_PROJECT_GET_IFACE (obj)->remove_node (obj, node, err);
}

/* Default implementation */
static gboolean
ianjuta_project_remove_node_default (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
 * ianjuta_project_remove_property:
 * @obj: Self
 * @node: (transfer none): Node
 * @id: (transfer none): Property
 * @name: (allow-none) (transfer none): Name for map property
 * @err: Error propagation and reporting
 *
 * Remove a property of the node
 *
 * Return value: TRUE if the node is removed
 */
gboolean
ianjuta_project_remove_property (IAnjutaProject *obj, AnjutaProjectNode *node,   const gchar *id,   const gchar *name, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), FALSE);
	g_return_val_if_fail ((node == NULL) ||ANJUTA_IS_PROJECT_NODE(node), FALSE);
	return IANJUTA_PROJECT_GET_IFACE (obj)->remove_property (obj, node, id, name, err);
}

/* Default implementation */
static gboolean
ianjuta_project_remove_property_default (IAnjutaProject *obj, AnjutaProjectNode *node,   const gchar *id,   const gchar *name, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
 * ianjuta_project_save_node:
 * @obj: Self
 * @node: (transfer none): Project node to save
 * @err: Error propagation and reporting
 *
 * Save a project node
 *
 * Return value: TRUE if the node has been saved without error
 */
gboolean
ianjuta_project_save_node (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), FALSE);
	g_return_val_if_fail ((node == NULL) ||ANJUTA_IS_PROJECT_NODE(node), FALSE);
	return IANJUTA_PROJECT_GET_IFACE (obj)->save_node (obj, node, err);
}

/* Default implementation */
static gboolean
ianjuta_project_save_node_default (IAnjutaProject *obj, AnjutaProjectNode *node, GError **err)
{
	g_return_val_if_reached (FALSE);
}

/**
 * ianjuta_project_set_property:
 * @obj: Self
 * @node: (transfer none): Node
 * @id: (transfer none): Property
 * @name: (allow-none) (transfer none): Name for map property
 * @value: (transfer none): Value
 * @err: Error propagation and reporting
 *
 * Change a properties on node.
 *
 * Return value: (allow-none) (transfer none): The new property of NULL if the property cannot be set
 */
AnjutaProjectProperty *
ianjuta_project_set_property (IAnjutaProject *obj, AnjutaProjectNode *node,   const gchar *id,   const gchar *name,   const gchar *value, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_PROJECT(obj), NULL);
	g_return_val_if_fail ((node == NULL) ||ANJUTA_IS_PROJECT_NODE(node), NULL);
	return IANJUTA_PROJECT_GET_IFACE (obj)->set_property (obj, node, id, name, value, err);
}

/* Default implementation */
static AnjutaProjectProperty *
ianjuta_project_set_property_default (IAnjutaProject *obj, AnjutaProjectNode *node,   const gchar *id,   const gchar *name,   const gchar *value, GError **err)
{
	g_return_val_if_reached (NULL);
}

static void
ianjuta_project_base_init (IAnjutaProjectIface* klass)
{
	static gboolean initialized = FALSE;

	klass->add_node_after = ianjuta_project_add_node_after_default;
	klass->add_node_before = ianjuta_project_add_node_before_default;
	klass->get_node_info = ianjuta_project_get_node_info_default;
	klass->get_root = ianjuta_project_get_root_default;
	klass->is_loaded = ianjuta_project_is_loaded_default;
	klass->load_node = ianjuta_project_load_node_default;
	klass->remove_node = ianjuta_project_remove_node_default;
	klass->remove_property = ianjuta_project_remove_property_default;
	klass->save_node = ianjuta_project_save_node_default;
	klass->set_property = ianjuta_project_set_property_default;
	
	if (!initialized) {

		/* Signals */
		/**
		* IAnjutaProject::file-changed:
		* @obj: Self
		* @node: Node to be reloaded.
		*
		* This signal is emitted when the project is changed on the disk. The
		* corresponding node has to be reloaded.
		*/
		g_signal_new ("file-changed",
			IANJUTA_TYPE_PROJECT,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaProjectIface, file_changed),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__POINTER,
			G_TYPE_NONE,
			1,
			G_TYPE_POINTER);


		/**
		* IAnjutaProject::node-changed:
		* @obj: Self
		* @node: Changed node.
		    * @error: Error while changing node
		*
		* This signal is emitted when a node is changed by a function of this
		* interface. The error argument is not NULL if the change was not
		 	* possible. The corresponding node need to be saved.
		*/
		g_signal_new ("node-changed",
			IANJUTA_TYPE_PROJECT,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaProjectIface, node_changed),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__POINTER_BOXED,
			G_TYPE_NONE,
			2,
			G_TYPE_POINTER,
			G_TYPE_ERROR);


		/**
		* IAnjutaProject::node-loaded:
		* @obj: Self
		* @node: Loaded node.
		    * @error: Error while loading node
		*
		* This signal is emitted when a node is loaded. It returns an error if the
		 	* load operation fail.
		*/
		g_signal_new ("node-loaded",
			IANJUTA_TYPE_PROJECT,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaProjectIface, node_loaded),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__POINTER_BOXED,
			G_TYPE_NONE,
			2,
			G_TYPE_POINTER,
			G_TYPE_ERROR);


		/**
		* IAnjutaProject::node-saved:
		* @obj: Self
		* @node: Saved node.
		    * @error: Error while saving node
		*
		* This signal is emitted when a node is saved. It returns an error if the
		 	* save operation fail.
		*/
		g_signal_new ("node-saved",
			IANJUTA_TYPE_PROJECT,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaProjectIface, node_saved),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__POINTER_BOXED,
			G_TYPE_NONE,
			2,
			G_TYPE_POINTER,
			G_TYPE_ERROR);


		initialized = TRUE;
	}
}

GType
ianjuta_project_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaProjectIface),
			(GBaseInitFunc) ianjuta_project_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaProject", &info, 0);
		g_type_interface_add_prerequisite (type, G_TYPE_OBJECT);
	}
	return type;			
}

GType
ianjuta_project_error_get_type (void)
{
	static const GEnumValue values[] =
	{
		{ IANJUTA_PROJECT_ERROR_SUCCESS, "IANJUTA_PROJECT_ERROR_SUCCESS", "error-success" }, 
		{ IANJUTA_PROJECT_ERROR_DOESNT_EXIST, "IANJUTA_PROJECT_ERROR_DOESNT_EXIST", "error-doesnt-exist" }, 
		{ IANJUTA_PROJECT_ERROR_ALREADY_EXISTS, "IANJUTA_PROJECT_ERROR_ALREADY_EXISTS", "error-already-exists" }, 
		{ IANJUTA_PROJECT_ERROR_VALIDATION_FAILED, "IANJUTA_PROJECT_ERROR_VALIDATION_FAILED", "error-validation-failed" }, 
		{ IANJUTA_PROJECT_ERROR_PROJECT_MALFORMED, "IANJUTA_PROJECT_ERROR_PROJECT_MALFORMED", "error-project-malformed" }, 
		{ IANJUTA_PROJECT_ERROR_WRONG_PARENT, "IANJUTA_PROJECT_ERROR_WRONG_PARENT", "error-wrong-parent" }, 
		{ IANJUTA_PROJECT_ERROR_NOT_SUPPORTED, "IANJUTA_PROJECT_ERROR_NOT_SUPPORTED", "error-not-supported" }, 
		{ IANJUTA_PROJECT_ERROR_GENERAL_FAILURE, "IANJUTA_PROJECT_ERROR_GENERAL_FAILURE", "error-general-failure" }, 
		{ 0, NULL, NULL }
	};

	static GType type = 0;

	if (! type)
	{
		type = g_enum_register_static ("IAnjutaProjectError", values);
	}

	return type;
}

GType
ianjuta_project_probe_get_type (void)
{
	static const GEnumValue values[] =
	{
		{ IANJUTA_PROJECT_PROBE_FILES, "IANJUTA_PROJECT_PROBE_FILES", "probe-files" }, 
		{ IANJUTA_PROJECT_PROBE_MAKE_FILES, "IANJUTA_PROJECT_PROBE_MAKE_FILES", "probe-make-files" }, 
		{ IANJUTA_PROJECT_PROBE_PROJECT_FILES, "IANJUTA_PROJECT_PROBE_PROJECT_FILES", "probe-project-files" }, 
		{ 0, NULL, NULL }
	};

	static GType type = 0;

	if (! type)
	{
		type = g_enum_register_static ("IAnjutaProjectProbe", values);
	}

	return type;
}
