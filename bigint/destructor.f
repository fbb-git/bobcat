inline BNCTX::~BNCTX()
{
    BN_CTX_free(d_ctx);
}
