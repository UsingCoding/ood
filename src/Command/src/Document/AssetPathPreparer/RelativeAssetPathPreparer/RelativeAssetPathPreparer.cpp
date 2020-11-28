#include "RelativeAssetPathPreparer.hpp"

IAssetPathPreparer::Path RelativeAssetPathPreparer::Prepare(const Path & path)
{
    return IAssetPathPreparer::Path("images") / path.filename();
}
