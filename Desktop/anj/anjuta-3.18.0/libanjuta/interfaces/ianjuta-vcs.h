/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-vcs.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_VCS_H_
#define _IANJUTA_VCS_H_

#include <glib-object.h>
#include <gio/gio.h>
#include <libanjuta/anjuta-vcs-status.h>
#include <libanjuta/anjuta-async-notify.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_VCS (ianjuta_vcs_get_type ())
#define IANJUTA_VCS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_VCS, IAnjutaVcs))
#define IANJUTA_IS_VCS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_VCS))
#define IANJUTA_VCS_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_VCS, IAnjutaVcsIface))

#define IANJUTA_TYPE_VCS_ERROR (ianjuta_vcs_error_get_type())

#define IANJUTA_VCS_ERROR ianjuta_vcs_error_quark()

typedef struct _IAnjutaVcs IAnjutaVcs;
typedef struct _IAnjutaVcsIface IAnjutaVcsIface;

/**
 * IAnjutaVcsError:
 * @IANJUTA_VCS_UNKNOWN_ERROR: Unkown error
 	 *
 	 * These enumeration is used to specify errors.
 */
typedef enum {
	IANJUTA_VCS_UNKOWN_ERROR
} IAnjutaVcsError;

    /**
     * IAnjutaVcsStatusCallback:
     * @file: File representing the file for which status is given
     * @status: #AnjutaVcsStatus for the file represented by @file.
     * @user_data: User data
     *
     * Callback called for each status record returned by
     * ianjuta_vcs_query_status.
     */
typedef void (*IAnjutaVcsStatusCallback) (GFile* file, AnjutaVcsStatus status, gpointer user_data);

    /**
     * IAnjutaVcsDiffCallback:
     * @file: File being diffed
     * @diff: Diff data
     * @user_data: User data
     *
     * Called when diff data comes from ianjuta_vcs_diff.
     */
typedef void (*IAnjutaVcsDiffCallback) (GFile* file, const gchar* diff, gpointer user_data);



struct _IAnjutaVcsIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*status_changed) (IAnjutaVcs *obj);

	void (*add) (IAnjutaVcs *obj, GList* files,  AnjutaAsyncNotify *notify, GError **err);
	void (*checkout) (IAnjutaVcs *obj, const gchar *repository_location,  GFile *dest,  GCancellable *cancel,  AnjutaAsyncNotify *notify, GError **err);
	void (*diff) (IAnjutaVcs *obj, GFile* file,  IAnjutaVcsDiffCallback callback,  gpointer user_data,  GCancellable* cancel,  AnjutaAsyncNotify *notify, GError **err);
	void (*query_status) (IAnjutaVcs *obj, GFile* file,  IAnjutaVcsStatusCallback callback,  gpointer user_data,  GCancellable* cancel,  AnjutaAsyncNotify *notify, GError **err);
	void (*remove) (IAnjutaVcs *obj, GList* files,  AnjutaAsyncNotify *notify, GError **err);

};

GType ianjuta_vcs_error_get_type (void);

GQuark ianjuta_vcs_error_quark     (void);
GType  ianjuta_vcs_get_type        (void);

void ianjuta_vcs_add (IAnjutaVcs *obj, GList* files,  AnjutaAsyncNotify *notify, GError **err);

void ianjuta_vcs_checkout (IAnjutaVcs *obj, const gchar *repository_location,  GFile *dest,  GCancellable *cancel,  AnjutaAsyncNotify *notify, GError **err);

void ianjuta_vcs_diff (IAnjutaVcs *obj, GFile* file,  IAnjutaVcsDiffCallback callback,  gpointer user_data,  GCancellable* cancel,  AnjutaAsyncNotify *notify, GError **err);

void ianjuta_vcs_query_status (IAnjutaVcs *obj, GFile* file,  IAnjutaVcsStatusCallback callback,  gpointer user_data,  GCancellable* cancel,  AnjutaAsyncNotify *notify, GError **err);

void ianjuta_vcs_remove (IAnjutaVcs *obj, GList* files,  AnjutaAsyncNotify *notify, GError **err);


G_END_DECLS

#endif
