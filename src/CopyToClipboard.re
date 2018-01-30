[@bs.module "copy-to-clipboard/CopyToClipboard"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~text: option(string),
      ~onCopy: option((string, bool) => unit)=?,
      ~options: option(Js.t({. debug: bool, message: string}))=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "text": from_opt(text),
          "onCopy": from_opt(onCopy),
          "options": from_opt(options)
        }
      ),
    children
  );