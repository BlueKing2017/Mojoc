/*
 * Copyright (c) scott.cgi All Rights Reserved.
 *
 * Since  : 2013-7-2
 * Author : scott.cgi
 */

#include "Engine/Extension/Spine/SkeletonBone.h"


static void SetToSetupPose(SkeletonBone* bone)
{
	Drawable*         drawable = bone->drawable;
	SkeletonBoneData* boneData = bone->boneData;

	ADrawableSetPosition2(drawable, boneData->x,      boneData->y);
	ADrawableSetScale2   (drawable, boneData->scaleX, boneData->scaleY);
	ADrawableSetRotationZ(drawable, boneData->rotationZ);
}


static void Init(SkeletonBoneData* boneData, SkeletonBone* outBone)
{
	ADrawable->Init(outBone->drawable);
	outBone->boneData = boneData;
	SetToSetupPose(outBone);
}


static SkeletonBone* Create(SkeletonBoneData* boneData)
{
	SkeletonBone* bone = (SkeletonBone*) malloc(sizeof(SkeletonBone));
	Init(boneData, bone);

	return bone;
}


struct ASkeletonBone ASkeletonBone[1] =
{
	Create,
	Init,
	SetToSetupPose,
};
